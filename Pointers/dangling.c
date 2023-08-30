#include <stdio.h>

unsigned long int f()
{
    int x = 5;
    int *ptr = &x;

    printf("%p\n", ptr);
    return (unsigned long int)ptr;
}


int main()
{
    int *ptr = (int*)f();
    printf("I just stole a variable\n");
    printf("%d\n", *ptr);
}