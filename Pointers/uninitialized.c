#include <stdio.h>

int main()
{
    int *ptr;

    /* one common pitfall is assuming that declaration of a pointer gives you
       an item to point at. */
    printf("%d\n", *ptr);
    
    return 0;
}