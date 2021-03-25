#include <sys/wait.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define SOCK0        0
#define SOCK1        1
#define BUF_SIZE  1024


/*
 * parent reads a file
 * parent writes file to socket 
 * child reads file from socket
 * child writes file back to socket
 * parent reads file back from socket 
 * parent prints file to terminal
 * file -> parent -> child -> parent -> terminal
 */

int main(int argc, char* argv[]) {
  int   sockets[2];
  pid_t pid;

  if (argc < 2) {
    printf("usage: %s file\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0) {
    perror("opening stream socket pair");
    exit(EXIT_FAILURE);
  }
  
  if ((pid = fork()) < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else
  if (pid == 0) {
    int  nbytes = 0;
    char buf[BUF_SIZE];
    
    /* read content from socket, write same content to socket */
    close(sockets[SOCK0]);
    while ((nbytes = read(sockets[SOCK1],buf,BUF_SIZE)) > 0) 
      write(sockets[SOCK1],buf,nbytes);
    close(sockets[SOCK1]);

    /* return gracefully */
    exit(EXIT_SUCCESS);
  }
  else {
    int  nbytes = 0;
    char buf[BUF_SIZE];
    
    /* this is the parent */
    close(sockets[SOCK1]);
    int fd = open(argv[1],O_RDONLY);

    /* read from socket and write to stdout */    
    while((nbytes = read(fd,buf,BUF_SIZE)) > 0) {
      if (write(sockets[SOCK0],buf,nbytes) < 0) {
	perror("writing message");
      }
      if (( nbytes = read(sockets[SOCK0],buf,BUF_SIZE)) > 0) {
	write(STDOUT_FILENO,buf,nbytes);
      } 
    }
    close(sockets[SOCK0]);

    /* wait for child and exit */
    if (waitpid(pid, NULL, 0) < 0) {
      perror("did not catch child exiting");
      exit(EXIT_FAILURE);
    }

    /* return gracefully */
    exit(EXIT_SUCCESS);
  }
}
