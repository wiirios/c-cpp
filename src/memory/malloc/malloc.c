#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *x;

    x = malloc(sizeof(char));

    if (x != NULL) printf("success!\n");
    else printf("error\n");

    strcpy(x, "Hello");    
    printf("%s\n", x);

    free(x);
    return 0;
}