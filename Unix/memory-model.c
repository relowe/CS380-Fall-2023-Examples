/* Demonstrate the UNIX memory model

   +--------+  Bottom (low addresses)
   | Text   |  
   |  (ro)  |   Program code 
   +--------+
   | Data   | 
   |  (rw)  |   Global Variables, Dynamic Hep
   +--------+
  Program Break
        |
       \ / Grows toward the top

     Unallocated Memory

       / \   Grows toward the bottom
        |
   +--------+
   | Stack  |  Local Variables and Call stack information
   |  (rw)  |
   +--------+ Top of memory (high addresses)
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_variable = 9;

void count_down(int x) 
{
  printf("%d: %p\n", x, &x);
  if(x) {
    count_down(x-1);
  }
}


int main()
{
  int local_variable = 10;
  void *ptr;

  // allocate a little memory
  ptr = malloc(1024);

  // print some addresses
  printf("&global_variable: %p\n", &global_variable);
  printf("&local_variable: %p\n", &local_variable);
  printf("ptr: %p\n", ptr);
  printf("main: %p\n", main);


  *(&local_variable) = 5;  // we can write to the local variables
  *(&global_variable) = 5; // we can write to the local variables
  *((int*) ptr) = 7;  // I can write to the dynamic memory
  // *((int*) main) = 9;  // we cannot write to the main function
  for(unsigned char *cptr = (unsigned char*) main; cptr <= ((unsigned char*) main) + 20; cptr++) {
    printf("%x ", *cptr);
  }
  putchar('\n');

  count_down(10);

  printf("Sbrk calls: \n");
  for(;;) {
    printf("%p\n", sbrk(1024*1024));
  }

  free(ptr);
}