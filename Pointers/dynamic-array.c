#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ar;
    int n;

    // ask about the array
    printf("How big of an array? ");
    scanf("%d", &n);

    // create the array
    ar = malloc(n * sizeof(int));


    for(int i=0; i<n; i++) {
        printf("%d: ", i);
        scanf("%d", ar + i);
    }


    for(int i=0; i<n; i++) {
        printf("%d\n", ar[i]); 
    }


    free(ar);
}