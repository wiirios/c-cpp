#include <stdio.h>

int main() {
    int value = 10;
    /* '&' is pointer to the andress of value in memory */
    int *andress = &value;

    printf("%d\n", value);
    printf("%d\n", andress);
    
    return 0;
}