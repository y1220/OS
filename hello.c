#include <stdio.h>
#include <stdlib.h>

int
main()
{
  char str[20];
  int age;

  fprintf(stdout, "insert your name\n");
  fscanf(stdin, "%s", str);
  
  fprintf(stdout, "insert your age\n");
  fscanf(stdin, "%d", &age);

  fprintf(stdout, "name: %s\t age: %d\n", str, age);
  
}