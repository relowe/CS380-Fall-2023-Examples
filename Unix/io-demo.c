#include <unistd.h>  /* <-- Header which contains most unix system calls */
#include <stdio.h>
#include <fcntl.h>

/*
 * Unix Metaphor
 *    "Everything is a file."
 *       - UNIX Kernel simply maintains buffers for I/O. (Stream)
 * 
 * File Descriptors
 * At program start, every UNIX program has 3 file descriptors:
 * 0 - standard input
 * 1 - standard output
 * 2 - standard error
 */

int main()
{
  int fd;
  
  /* syscall: int write(int fd, char *buffer, int n) 
       - fd: File Descriptor
       - buffer: Characters to write
       - n: number of characters to write
    Returns: Returns the number of characters written
      -1 on error
   */
  write(1, "Hello, world\n", 13);
  write(2, "Hello, error\n", 13);

  /*
   * Unix Permissions
   *  4 r - read
   *  2 w - write
   *  1 x - execute
   * Repeated for 3 groups
   *  Owner, Group, Everyone
   * Leading 0: Express a literal in octal (C)
   *   C Literals: 
   *        10 - decimal
   *       0xA - hexadecimal
   *       012 - octal
   */

  /* UNIX always opens a new stream with the lowest available file descriptor number */
  fd = open("file.txt", O_CREAT|O_TRUNC|O_WRONLY, 0600); 
  printf("Hey, I just opened file: %d\n", fd);
  write(fd, "Hello, file\n", 12);
  close(fd);


  /* here's a fun one! */
  close(1);
  fd = open("file2.txt", O_CREAT|O_TRUNC|O_WRONLY, 0600);
  printf("Hey, I just opened file: %d\n", fd);
  /* the above redirects std output to a file */
}