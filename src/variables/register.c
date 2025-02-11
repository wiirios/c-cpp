#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int pwr(register int m, register int e) {
    register int temp = 1;

    for (; e; e--) temp = temp * m;
    return temp;
}

int main() {
    printf("%d", pwr(4, 4));
    return 0;
}