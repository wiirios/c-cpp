#include <stdio.h>
#include <math.h>

int a, b, i, r;

int sum(int n) {
    // return (-(~n));
    return n;
}

// https://www.geeksforgeeks.org/multiply-an-integer-with-3-5/
int multiply(int n) {
    /* to calculate 2*x, left shift x by 1 and to calculate x/2, right shift x by 1. 
    after that, sum with n
    e.g: 2 * 3,5 == 7
    2 / 2 = 1
    2 * 2 = 4
    4 + 1 = 5
    5 + 2 = 7 */
    return (n << 1) + (n >> 1) + n;
}

int main() {
    printf("%d\n", 127^126);
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

    printf("%d\n", sum(100));
    printf("%d", multiply(2));

    return 0;
}