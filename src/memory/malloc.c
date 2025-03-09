#include <stdio.h>
#include <stdlib.h>

int main() {
    int *x;

    x = malloc(sizeof(int));

    if (x != NULL) printf("success!\n");
    else printf("error\n");

    *x = 30;
    printf("%d\n", *x);

    free(x);
    return 0;
}