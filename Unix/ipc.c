#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // establish a pipeline
  // ls | cat -n
  int p[2];  // pipe file descriptors

  //command arguments
  char *ls_argv[] = {"ls", NULL};
  char *cat_argv[] = {"cat", "-n", NULL};

  //create the pipe
  if(pipe(p)==-1) { 
    fprintf(stderr, "Could not create pipe\n");
    exit(-1);
  }

  // create the left hand child
  if(fork()==0) {
    // manipulate the file descriptors
    //   std output of the child is routed through the pipe
    close(1);  // close stdout
    dup(p[1]); // duplicates pipe write fd

    //close the pipe file descriptors
    close(p[0]);
    close(p[1]);

    //exec our command
    execvp(ls_argv[0], ls_argv);
  }

  // create the right hand child
  if(fork()==0) {
    // manipulate the file descriptors
    //   std input of the child is read from the pipe
    close(0);   // close stdin
    dup(p[0]);  // dup read side of the pipe 

    // close the pipe
    close(p[0]);
    close(p[1]);

    //exec our command
    execvp(cat_argv[0], cat_argv);
  }

  // the parent closes the pipe
  close(p[0]);
  close(p[1]);

  // wait for the children
  wait(NULL);
  wait(NULL);

  printf("All done\n");
  return 0;
}