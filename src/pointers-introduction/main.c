#include <stdio.h>

#define PI 3.14159
#define MAX_SIZE 6

void decompose(double x, long *init_part, double *frac_part) {
    *init_part = (long) x;
    *frac_part = x - *init_part;
}

void findMaxMin(int numbers[], int *max, int *min) {
    *max = *min = numbers[0];

    for (int i = 0; i < MAX_SIZE; i++) {
        if (numbers[i] > *max) *max = numbers[i];
        else if (numbers[i] < *min) *min = numbers[i];
    }

    printf("%d\n", *max);
    printf("%d\n", *min);
}

int main() {
    int value = 10;
    /* '&' is pointer to the andress of value in memory */
    int *andress = &value;

    printf("%d\n", value);
    printf("%d\n", andress); /* here i get the addresses of the variable */
    printf("%d\n", *andress); /* and here i get the VALUE associate with andress pointer*/

    /* output
        10
        655999
        10
    */

    long i = 0;
    double d = 0.0;
    double pi = PI;

    decompose(pi, &i, &d);
    /*
        '&i' and '&d' are the memory addresses of the variables 'i' and 'd', respectively, passed to the function 'decompose'.
        Inside the 'decompose' function:
            *init_part = (long) x;
                - The '*' operator dereferences the 'init_part' pointer, accessing and modifying the VALUE of the 'i' variable
                  directly in memory, not its address.
            
            *frac_part = x - *init_part;
                - The '*' operator dereferences the 'frac_part' pointer, accessing and modifying the VALUE of the 'd' variable
                  directly in memory, not its address.
        In summary, when calling 'decompose(pi, &i, &d)', we are passing the addresses of 'i' and 'd' so the function can
        change the values of these variables directly, without needing to return any values.
    */
    
    printf("%ld\n", i);
    printf("%f\n", d);

    int numbers[MAX_SIZE] = {10, 20, 30, 50, 40, 30}, max, min;
    /* int = 4 bytes */

    // printf("%d\n", sizeof(numbers) / sizeof(numbers[0])); /* 24 / 4 = 6 */

    findMaxMin(numbers, &max, &min);
    /*
        findMaxMin(numbers, &max, &min);
        here I am passing the memory address

        void findMaxMin(int numbers[], int *max, int *min) 
        and here I am getting the value

    */
    
    return 0;
}
