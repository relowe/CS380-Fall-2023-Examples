#include <stdio.h>

int main()
{
    int x=5;
    int y=5;
    int *px, *py;

    px = &x;
    py = &y;

    // a very easy mistake
    if(px == py) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    // correction
    if(*px == *py) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}