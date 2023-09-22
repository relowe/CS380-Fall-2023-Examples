/* processes are created using fork()
 *   fork() - creates a duplicate of the current process
 *     - return pid to the parent, 0 to the child
 *   wait(int*) - waits for a child process to die
 */
#include <stdio.h>
#include <unistd.h>

int main()
{
  int pid = fork();
  
  if(pid) {
    printf("I am the parent of process: %d\n", pid);
    for(;;);
    printf("Oh no! Child %d has died.\n", wait(NULL));
  } else {
    printf("I am the child: %d\n", pid);
  }

}