#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/* 
 * a simple shell: parent presents prompt, reads command,
 * forks a new process and tries to execlp the command. The 
 * parent waits for the command to end and gives the prompt 
 * again.
 */

int main(int argc, char** argv) {

  /* do this forever */
  for( ; ; ) {
    char*  command = NULL;
    size_t commcap = 0;

    /* give prompt, read command and null terminate it */
    fprintf(stdout, "> ");
    if( getline(&command, &commcap, stdin) <= 0 )
      break;
    command[strlen(command) - 1] = '\0';
    /* prompt again if empty */
    if( strcmp(command, "") == 0 )
      continue;
    /* exit if command is quit */
    if( strcmp(command, "quit") == 0 )
      break;
    
    /* call fork and check return value */
    pid_t pid;
    int   status;
    if((pid = fork()) < 0) {
      fprintf(stderr, "%s: can't fork command: %s\n", 
              argv[0], strerror(errno));
      continue;
    } else if(pid == 0) {
      /* child only */
      execlp(command, command, (char *)0);
      /* if I get here "execl" failed */
      fprintf(stderr, "%s: couldn't exec %s: %s\n", 
              argv[0], command, strerror(errno));
      /* terminate with error to be caught by parent */
      exit(EXIT_FAILURE);
    }

    /* shell waits for command to finish before giving prompt again */
    if ((pid = waitpid(pid, &status, 0)) < 0) 
      fprintf(stderr, "%s: waitpid error: %s\n", 
              argv[0], strerror(errno));
  }
  /* get here with a ^C and ^D */
  exit(EXIT_SUCCESS);
}
