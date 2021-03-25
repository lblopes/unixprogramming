#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

  /* check if exactly one argument is present */
  if(argc != 2) { 
    printf("usage: cat filename\n");
    exit(EXIT_FAILURE);
  }

  /* check if file can be opened and is readable */
  int fd = open(argv[1], O_RDONLY);
  if(fd == -1) {
    printf("error: cannot open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  /* read contents in blocks and print to terminal */
  int  nbytes;
  char buffer[BUFFER_SIZE]; 
  while( (nbytes = read(fd, buffer, BUFFER_SIZE)) != 0 )
    write(STDOUT_FILENO, buffer, nbytes);

  /* close file */
  close(fd);

  /* return gracefully */
  exit(EXIT_SUCCESS);
}
