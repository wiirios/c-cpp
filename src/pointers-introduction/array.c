#include <stdio.h>

int main() {
    int array[10], *p, *q, *u;

    p = &array[0];
    *p = 5;

    printf("%d\n", *p);

    /* Pointer Arithmetic */
    /*
        Making a pointer p point to an element of an array a isn’t particularly exciting. However, 
        by performing pointer arithmetic
        (or address arithmetic) on p, we
        can access the other elements of array. C supports three (and only tlu*ee) forms of
        pointer arithmetic:
        Adding an integer to a pointer
        Subtracting an integer from a pointer
        Subtracting one pointer from anothe

    */

    q = p + 1; /* q = array[1] address */
    *q = 10; /* array[1] = 10 */

    printf("%d\n", *p);
    printf("%d\n", *q);

    u = q + 5; /* u = array[6] address */
    *u = 50; /* array[6] = 50 */
    
    printf("%d\n", *u);

    u -= 2; /* array[4] */

    return 0;
}