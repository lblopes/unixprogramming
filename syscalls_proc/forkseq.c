#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) { 
  pid_t pid;

  /* fork a child process */
  if((pid = fork()) > 0)
    printf("parent: %d new child: %d\n", getpid(), pid);

  /* fork another child process */
  if((pid = fork()) > 0)
    printf("parent: %d new child: %d\n", getpid(), pid);

  /* and fork another */
  if((pid = fork()) > 0)
    printf("parent: %d new child: %d\n", getpid(), pid);
 
  exit(EXIT_SUCCESS);
}
