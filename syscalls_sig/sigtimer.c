#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void read_sensor(int signum) {
  printf("calling sensor reading function\n");
}

int main (int argc, char* argv[]) {
  struct sigaction action;
  struct itimerval timer;

  /* install timer_handler as the signal handler for SIGVTALRM. */
  memset (&action, 0, sizeof (action));
  action.sa_handler = &read_sensor;
  sigaction (SIGVTALRM, &action, NULL);

  /* configure the timer to expire after 2.5 seconds */
  timer.it_value.tv_sec  = 2;
  timer.it_value.tv_usec = 500000;

  /* and every 2.5 seconds after that */
  timer.it_interval.tv_sec  = 2;
  timer.it_interval.tv_usec = 500000;

  /* 
   * start the timer 
   * it counts down whenever this process is executing. 
   */
  setitimer (ITIMER_VIRTUAL, &timer, NULL);

  /* Do busy work. */
  for( ; ; )
    ;
}
