#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ_END   0
#define WRITE_END  1
#define BUF_SIZE   256

int main(int argc, char* argv[]) {
  int   fd[2];
  pid_t pid;

  if (pipe(fd) < 0) {
    perror("pipe error");
    exit(EXIT_FAILURE);
  }

  if ((pid = fork()) < 0) {
    perror("fork error");
    exit(EXIT_FAILURE);
  } 
  else
  if (pid > 0) {
    int nbytes;
    char line[BUF_SIZE];    

    /* parent writes to pipe */
    close(fd[READ_END]);
    snprintf(line, BUF_SIZE,
	     "Hello child (%d)!  I'm your parent pid (%d).\n",
	     pid, getpid());
    if ((nbytes = write(fd[WRITE_END], line, strlen(line))) < 0) {
      fprintf(stderr, "Unable to write to pipe: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
    close(fd[WRITE_END]);
    
    /* wait for child and exit */
    if ( waitpid(pid, NULL, 0) < 0) {
      fprintf(stderr, "Unable to catch child exiting: %s\n", strerror(errno));       exit(EXIT_FAILURE);     
    }

    /* return gracefully */
    exit(EXIT_SUCCESS);
  } 
  else {
    int  nbytes;
    char line[BUF_SIZE];
    
    /* child reads from pipe */
    close(fd[WRITE_END]);
    if ((nbytes = read(fd[READ_END], line, BUF_SIZE)) < 0 ) {
      fprintf(stderr, "Unable to read from pipe: %s\n", strerror(errno));
      exit(EXIT_FAILURE);     
    }
    close(fd[READ_END]);

    /* write message from parent */
    write(STDOUT_FILENO, line, nbytes);

    /* return gracefully */
    exit(EXIT_SUCCESS);
  }
}
