#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

pid_t pLeft (void);
void pRight (void);

int
main()
{
  pid_t pid, pidTmp;

  fprintf (stdout, "P1 (pid=%d)\n", getpid());
  pid = fork();// pid of child
  if (pid == 0) { // child
    //sleep (1);
    pRight ();
    exit (0);
  } else { // parent
    //sleep (1);
    pidTmp = pLeft ();
    // Check whether pLeft got the exit from P8
    //if (pidTmp!=pid) {
    if (pidTmp==getpid()) {
       // Exit from P8 still to catch
       pidTmp = wait ((int *) 0);
       fprintf (stdout, "1. pid=%d return from wait pid=%d\n",
         getpid(), pidTmp);
    }
    fprintf (stdout, "P9 (pid=%d)\n", getpid());
    return (0);
  }
}

pid_t
pLeft () {
  pid_t pid, pidRet, pidTmp, pidP;
  pidP=getpid();
  fprintf (stdout, "P2 (pid=%d)\n", getpid());
  pid = fork();
  if (pid == 0) {// child
    //sleep (1);
    fprintf (stdout, "P5 (pid=%d)\n", getpid());
    exit (0);
  } else { // parent
    fprintf (stdout, "P4 (pid=%d)\n", getpid());
    //sleep (5);
    // Wait once
    pidRet = wait ((int *) 0);
    fprintf (stdout, "2. pid=%d return from wait pid=%d\n",
      getpid(), pidRet);
    // IFF P5 go on, IFF P8 wait again 
    fprintf(stderr, "----------------LEFT: pid:%d, pidRet:%d\n",pid, pidRet);
    if (pidRet != pid) { // wait will return child pid, fork will return child pid for parent
      pidTmp = wait ((int *) 0);
      fprintf (stdout, "3. pid=%d return from wait pid=%d\n",
        getpid(), pidTmp);
    } 
    fprintf (stdout, "P7 (pid=%d)\n", getpid());
    //return (pidRet);
    return (pidP);
  }
}

void
pRight () {
  pid_t pid, pidTmp;

  //sleep(1);
  fprintf (stdout, "P3 (pid=%d)\n", getpid());
  pid = fork();
  if (pid == 0) {// child
    //sleep (1);
    fprintf (stdout, "P6 (pid=%d)\n", getpid());
    exit (0);
  } else { // parent
    //sleep (1);
    pidTmp = wait ((int *) 0);
    fprintf(stderr, "----------------RIGHT: pid:%d, pidTmp:%d\n",pid, pidTmp);
    fprintf (stdout, "4. pid=%d return from wait pid=%d\n",
      getpid(), pidTmp);
    fprintf (stdout, "P8 (pid=%d)\n", getpid());
    exit (0);
  }
}