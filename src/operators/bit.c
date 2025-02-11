#include <stdio.h>
#include <math.h>

int a, b, i, r;

int main() {
    // printf("%d\n", 127^120);

    printf("%d\n", 128|3);

    a = 2;
    b = 9;
    i = 1;

    printf("%d\n", a*a);
    printf("%d\n", b*b);

    printf("%d\n", a << 1);
    printf("%d\n", b << 1);

    printf("%s\n", "--");

    /* 2 ^ 10*/
    for (; i < 10; i++) {
        a = a << 1;
        printf("%d\n", a);
    }

    int r;

    

    return 0;
}