#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */
#include <string.h>

char *concat(char *first, char *second) {
    char *result;

    result = malloc((strlen(first) + strlen(second)) + 1);

    if (result == NULL) exit(EXIT_FAILURE);

    strcpy(result, first);
    strcat(result, second);

    return result;
}

int main() {
    char *s;
    s = concat("hello", "world");

    return 0;
}