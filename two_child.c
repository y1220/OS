#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main (
  int argc,
  char *argv[]
  )
{
  pid_t pid1;
  pid_t pid2;
  int i; 
  int n = atoi (argv[1]);
  int t = atoi (argv[2]);
  int counter=0;
  int gcnt=0;

  fprintf(stdout, "1: PID=%d; PPID=%d; counter=%d\n",
    getpid(), getppid(),counter); 

  for (i=0; i<n; i++) {
      pid1 = fork();
      fprintf(stdout, "------------------- PID=%d i=%d----------------------\n", pid1, i);
      if (pid1 == 0){
  	     // Child1
          counter++; 
  	     fprintf(stdout, "2: PID=%d; PPID=%d; counter=%d\n",
         getpid(), getppid(),counter);
      } else {
      	 //Parent
          pid2 = fork();
          if (pid2 == 0){
             // Child2
            	counter++; 
              fprintf(stdout, "3: PID=%d; PPID=%d; counter=%d\n",
              getpid(), getppid(),counter);
          } else { 
             //Parent
              fprintf(stdout, "4: Process %d exiting\n", getpid()); 
              exit(0);// Stop Parent
          }
      }
  }

  fprintf(stdout, "5: PID %d. Leaf. Sleep for %d secs. gcnt %d\n",
    getpid(),t, gcnt); 
    gcnt++; 
  sleep(t);
  fprintf(stdout, "6: PID %d. Leaf. Sleep for %d secs. gcnt %d\n",
    getpid(),t, gcnt); 
//exit(0);
return (0);
}