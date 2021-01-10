#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main () {
  int i = 0;
 
  setbuf(stdout,0);
  // child will terminate immediately!!
  while (i<=2 && fork()){ 
    if (!fork()) {
      fprintf (stdout, "1. Running Exec ...");
      // terminate just after print of i*i (NO CALCULATION)
      execlp ("echo", "echo", "2. i*i", (char *) 0);
    }
    i++;
    fprintf (stdout, "3. Running System ...");
    system ("echo 4. i+i");
  }
 
  return (0);
} 

 /* OUTPUT
 
    3. Running System ...1. Running Exec ...2. i*i
    4. i+i
    3. Running System ...1. Running Exec ...2. i*i
    4. i+i
    3. Running System ...1. Running Exec ...2. i*i
    4. i+i

  */