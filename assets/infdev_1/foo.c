#include <stdio.h>
#include <stdlib.h>

int main() {
    int *x = malloc(sizeof(int));
    
    // *x = 20;
    free(x);

    printf("%i \n", *x);
    return 0;
}