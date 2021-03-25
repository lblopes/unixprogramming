#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_ARGS  16

void get_args(char* command, char** args) {
  char* p;
  int   i = 0;
  while ( (p = strsep(&command, " ")) != NULL) 
    args[i++] = strdup(p);
  args[i] = NULL;
}

int main(int argc, char* argv[]) {
  
  /* do this until you get a ^C or a ^D */
  for( ; ; ) {
    char*  command = NULL;
    size_t commcap = 0;
    char*  args[MAX_ARGS];

    /* give prompt, read command and null terminate it */
    fprintf(stdout, "> ");
    if( getline(&command, &commcap, stdin) <= 0)
      break;
    command[strlen(command) - 1] = '\0';
    /* prompt again if empty */
    if( strcmp(command, "") == 0 )
      continue;
    /* exit if command is quit */
    if( strcmp(command, "quit") == 0 )
      break;    
  
    /* call fork and check return value */
    pid_t  pid;
    if((pid = fork()) < 0) {
      fprintf(stderr, "%s: can't fork command: %s\n", 
              argv[0], strerror(errno));
      continue;
    } 
    else if(pid == 0) {
      /* break the command into tokens for execvp */
      get_args(command, args);    
      /* run execvp */
      execvp(args[0], args);
      /* if I get here "execvp" failed */
      fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
      /* terminate with error to be caught by parent */
      exit(EXIT_FAILURE);
    }

    /* shell waits for command to finish before giving prompt again */
    if ((pid = waitpid(pid, NULL, 0)) < 0) 
      fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
  }
  exit(EXIT_SUCCESS);
}

