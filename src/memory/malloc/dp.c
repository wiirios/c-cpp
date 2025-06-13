#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* Dangling Pointer */
    char *x;

    x = malloc(sizeof(char));

    free(x);

    strcpy(x, "hello"); // !
    
    return 0;
}