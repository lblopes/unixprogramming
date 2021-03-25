#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  pid_t pid;
  
  /* fork a child process */
  if ((pid = fork()) < 0 ) {
    printf("%s: cannot fork()\n", argv[0]);
    exit(EXIT_FAILURE);
  } else if (pid == 0) { 
    /* child process */
    if (execlp(argv[1],argv[1],NULL) < 0) {
      printf("failed to exec %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  } else { 
    /* parent process */
    if (waitpid(pid, NULL, 0) < 0) {
      printf("%s: cannot wait for child\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }
  exit(EXIT_SUCCESS);
}
