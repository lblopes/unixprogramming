#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) { 
  pid_t pid;

  /* fork child processes */
  for ( int i = 0 ; i < 3 ; i++ )
    if((pid = fork()) > 0)
      printf("parent: %d new child: %d\n", getpid(), pid);
 
  exit(EXIT_SUCCESS);
}
