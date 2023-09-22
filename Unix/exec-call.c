#include <stdio.h>
#include <unistd.h>

int main()
{
  char * exec_argv[] = {"ls", NULL};

  printf("I am about to run exec\n");
  execvp(exec_argv[0], exec_argv);
  printf("I should never get here.");
}