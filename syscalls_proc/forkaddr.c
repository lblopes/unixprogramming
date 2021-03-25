#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int value = 0;

int main(int argc, char* argv[]) { 
  pid_t pid;

  if ((pid = fork()) < 0 ) {
    printf("%s: cannot fork()\n", argv[0]);
    exit(EXIT_FAILURE);
  } 
  else if (pid == 0) { 
    /* child process */ 
    value = 1;
    printf("value@child  = %d, value address = %p\n",value,&value); 
    exit(EXIT_SUCCESS);
  } else { 
    /* parent process */
    if (waitpid(pid, NULL, 0) < 0) {
      printf("%s: cannot wait for child\n", argv[0]);
      exit(EXIT_FAILURE);
    }
    printf("value@parent = %d, value address = %p\n",value,&value);
    exit(EXIT_SUCCESS);
  }
}
