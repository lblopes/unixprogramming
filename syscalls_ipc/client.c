#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE   1024

/*
 * this is the client side 
 */

int main(int argc, char *argv[]) {
  int    sock;
  struct sockaddr_in name;
  struct hostent *hp;

  /* check for at least one argument */
  if (argc < 4) {
    printf("usage: %s hostname port file\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  /* create socket on which to send */
  if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("opening datagram socket");
    exit(EXIT_FAILURE);
  }

  /* destination is constructed from hostname 
     and port both given in the command line */
  if ((hp = gethostbyname(argv[1])) == 0) {
    fprintf(stderr, "%s: unknown host\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  memcpy(&name.sin_addr, hp->h_addr, hp->h_length);
  name.sin_family = AF_INET;
  name.sin_port = htons(atoi(argv[2]));

  /* connect to given port */
  if(connect(sock, (struct sockaddr *)&name, sizeof(name)) < 0) {
    perror("connecting to server socket");
    exit(EXIT_FAILURE);
  }

  int fd = open(argv[3],O_RDONLY);

  /* read from file and write to socket */    
  int  nbytes = 0;
  char buf[BUF_SIZE];
  while((nbytes = read(fd,buf,BUF_SIZE)) > 0) {
    if (write(sock, buf, nbytes) < 0) {
      perror("sending datagram message");
      exit(EXIT_FAILURE);	
    }
  }

  /* close socket */
  close(sock);

  /* return gracefully */  
  exit(EXIT_SUCCESS);
}
