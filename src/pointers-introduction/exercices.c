#include <stdio.h>

#define MAX 6

int sum(int *a, int *b) {
    while (*b != 0) {
        int carry = (*a & *b) << 1;
        *a = *a ^ *b;
        *b = carry;
    }

    return *a;
}

size_t stlen(const char *d) {
    size_t l = 0;

    while (*d != 0) {
        l++;
        d++;
        /* the NULL character is '\0' or 0*/
    }

    return l;
}

void swap(int *c) {
    int i;
    int max = MAX;

    for (int i = 0; i < MAX / 2; i++) {
        int temp = c[i];
        c[i] = c[max - 1];
        c[max - 1] = temp;
        max--;
    }
}

void swapAB(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int sumall(int *c) {
    int result = 0;
    
    for (int i = 0; i < MAX; i++) {
        result += *c;
        c++;
    }

    return result;
}

int main() {
    int a, b;
    a = 5;
    b = 2;

    int c[MAX] = {1, 2, 3, 4, 5, 6};

    char d[] = "Hello";

    // printf("%d\n", sum(&a, &b));
    // printf("%d\n", &c[0]);
    // printf("%d", &c[1]);

    // printf("%d\n", stlen(&d[0]));

    // printf("%d", stlen(&d[0]));
    /*
        &c[0] = 650001
    
    */

    // swap(&c[0]);
    // for (int i = 0; i < MAX; i++) {
    //     printf("%d\n", c[i]);
    // }
    // printf("%d", c[4]);

    // printf("%d", sumall(&c[0])); /* out 21 */

    swapAB(&a, &b);
    printf("%d\n", a);
    printf("%d", b);

    return 0;
}