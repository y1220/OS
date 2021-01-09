/* Exam 2020/06/16 - Exercise 2 */
 
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
 
int last_sig = -1;
int last_last_sig = -1;
int finish = 0;
 
 
void sign_handler(int sig){
 
  if (sig==SIGUSR1) printf("Signal received from P1\n");
  else if (sig==SIGUSR2) printf("Signal received from P2\n");
 
  /* It receives 3 consecutive signals from the same process */
  if (sig == last_sig && last_sig == last_last_sig) {
    finish = 1;
  } else {
    last_last_sig = last_sig;
    last_sig = sig;
  }
}
 
 
int main() {
  char cmd[100];
  pid_t pid1, pid2;
 
  if ( (signal(SIGUSR1, sign_handler) == SIG_ERR) || (signal(SIGUSR2, sign_handler ) == SIG_ERR) ) {
    printf("Error initializing signal handler");
    exit(-1);
  }
 
  pid1 = fork();
  if (!pid1) {
    /* P1 */
    while (1) {
      sleep( rand()%2 );
      kill(getppid(), SIGUSR1);
    }
  } else {
    pid2 = fork();
    if (!pid2) {
      /* P2 */
      while (1) {
        sleep( rand()%3 );
        kill(getppid(), SIGUSR2);
      }
    }         
  }
 
  /* Parent */
  while (1) {
    pause();
    if (finish) {
      /* Kill P1 with a shell command */
      sprintf(cmd, "kill -9 %d", pid1);
      system(cmd);
      /* Kill P2 with a shell command */
      sprintf(cmd, "kill -9 %d", pid2);
      system(cmd);
      exit(0);
    }
  }
 
}