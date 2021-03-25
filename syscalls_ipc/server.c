#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE   1024

/*
 * this is the server side 
 */

int main(int argc, char* argv[]) {
  int       sock;
  socklen_t length;
  struct sockaddr_in name;

  /* create socket from which to read */
  if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("opening datagram socket");
    exit(EXIT_FAILURE);
  }

  /* create name with wildcards - port will be given by OS */
  name.sin_family = AF_INET;
  name.sin_addr.s_addr = INADDR_ANY;
  name.sin_port = 0;
  if (bind(sock, (struct sockaddr *)&name, sizeof(name))) {
    perror("binding datagram socket");
    exit(EXIT_FAILURE);
  }

  /* find assigned port value and print it out */
  length = (socklen_t)sizeof(name);
  if (getsockname(sock, (struct sockaddr *)&name, &length)) {
    perror("getting socket name");
    exit(EXIT_FAILURE);
  }
  printf("server listening at port %d\n", ntohs(name.sin_port));
  printf("..............................\n");

  /* read eternally from the socket */
  int  nbytes;
  char buf[BUF_SIZE];
  for( ; ; ) 
    while ((nbytes = read(sock, buf, BUF_SIZE)) > 0) {
      write(STDOUT_FILENO, buf, nbytes);
      printf("..............................\n");
    }

  /* close socket - never gets here */ 
  close(sock);

  /* return gracefully - never gets here */ 
  exit(EXIT_SUCCESS);
}
