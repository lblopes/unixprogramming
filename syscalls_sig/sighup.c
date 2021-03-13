#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/errno.h>

/* program parameters */ 
static int   param1;
static int   param2;
static float param3;
static float param4;

void read_parameters() {
  FILE *fp;
     
  if ( (fp = fopen(".config", "r")) == NULL ){
    printf("Missing configuration file\n");
    exit(EXIT_FAILURE);
  }

  fscanf(fp, "param1: %d\n", &param1);
  fscanf(fp, "param2: %d\n", &param2);
  fscanf(fp, "param3: %f\n", &param3);
  fscanf(fp, "param4: %f\n", &param4);  
  
  fclose(fp);
}

void print_parameters() {
  printf("param1: %d\n", param1);
  printf("param2: %d\n", param2);
  printf("param3: %f\n", param3);
  printf("param4: %f\n", param4);  
}

/* 
 * SIGHUP signals are caught and force process 
 * to re-read configuration file and update 
 * parameter values 
 */
void handler (int signum) {
  read_parameters();
  printf ("reading parameters, values are:\n");
  print_parameters();
}

int main (int argc, char* argv[]) {
  if (signal(SIGHUP, handler) == SIG_ERR) {
    fprintf(stderr, "Can't catch SIGHUP: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

  /* print PID for reference */
  printf("my PID is %d\n", getpid());

  /* read initial parameters */
  read_parameters();
  
  /* stick around and catch SIGHUP signals */
  printf("working...\n");
  for ( ; ; )
    ;
}
