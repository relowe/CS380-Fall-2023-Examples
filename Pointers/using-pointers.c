#include <stdio.h>

int main() {
  int x;
  int *ptr;
  char *cptr;

  /* set up and use the pointer */
  ptr = &x;
  *ptr = 682344;

  /* display the variable and pointer information */
  printf("x=%d ptr=%p\n", x, ptr);
  printf("sizeof(x)=%d sizeof(ptr)=%d\n", (int)sizeof(x), (int)sizeof(ptr));
  printf("ptr+5=%p\n", ptr + 5);

  /* character pointer */
  cptr = (char *)ptr;
  printf("cptr=%p sizeof(cptr)=%d\n", cptr, (int)sizeof(cptr));
  for(; *cptr; cptr++) {
    putchar(*cptr);
  }
}