#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>

static long *sseed;
bool hasSeed = false;

/*
    127, 508, 1016, 8128, 130047, 166465, 2663440, 15981641
*/

static int defaultSeeds[] = {
    0x7f, 0x1fc, 0x3f8, 0x1fc0, 0x1FBFF, 0x28A41, 0x28a410, 0xF3DC49
};

int ASCII[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};

void fatal(char *msg) {
    printf("Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

/*

*/
int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;

    for (int i = 0; i < count; i++) total += va_arg(args, int);
    
    va_end(args);

    return total;
}

/* this does what you think it does */

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

/* 1 for true and 0 for false */
int is_greater(int a, int b) {
    return (a > b) ? true : false;
}

int isgreaterorequal(int a, int b) {
    return (a >= b) ? true : false;
}

int is_less(int a, int b) {
    return (a < b) ? true : false;
}

int islessorequal(int a, int b) {
    return (a <= b) ? true : false;
}

/* reverse the number ,; */
int reverse(int num) {
    int r = 0;

    while (num > 0) {
        r = r * 10 + num % 10;
        num = num / 10;
    }

    return r;
}
/*
    reverse the number in memory
*/
void reverse_num(int* num) {
    int r = 0;

    while (*num > 0) {
        r = r * 10 + *num % 10;
        *num = *num / 10;
    }

    *num = r;
}

/* exponent cal */
double pow(double a, double b) {
    int c = a;

    for (int i = 1; i < b; i++) a *= c;

    return a;
}

/*
    converts the given char to integer. (if in the char has a char this shit broke)
*/
int valueof(const char *ch) {
    int hasN = 0;
    int n1;
    
    while (*ch) {
        int chInt = *ch;
        
        for (int i = 0; i < 11; i++) {
            if (*ch < 48 || *ch > 57) fatal("Invalid char");
            else if (chInt == ASCII[i]) { 
                if (hasN == 0) {
                    n1 = i;
                    hasN = 1;
                } else if (hasN == 1) {
                    int factor = (int) pow(10, (int) log10(i) + 1); 
                    n1 = (n1 * factor) + i;
                }
            }
        }

        *ch++;
    }

    return n1;
}

double root(const double a) {
    double r = 0.0;
    int i = 0;

    for (;;) {
        r = a / i;
        if (pow(r, 2) == a) return r;
        else {
            i++;
            r = 0;
        }
    }

    return 0.0;
}

void setSeed(long seed) {
    sseed = malloc(sizeof(int));

    sseed != NULL ? *sseed = 0 : fatal("Error (re)allocating memory");

    *sseed = (seed < 0) ? -(seed) : seed;
    hasSeed = true;
}

void removeSeed() {
    sseed = 0;
    hasSeed = false;

    free(sseed);
}

/*
    Generating a truly random number and not a pseudo random number is a complex challenge.  
    This method attempts to produce pseudorandom values using a seed (`sseed`)  
    and the current time to influence the variation of the generated numbers.

    One possibility for generating a "more random" number could involve using more unpredictable system parameters,  
    such as the current CPU temperature, RAM usage, available virtual memory, etc.
*/

long random() {
    long a = *sseed;

    time_t timer;

    timer = time(NULL);
    timer %= 8;

    if (hasSeed) {
        if (a > 0 && a < 3) a *= 5;

        for (int i = 0; i < timer; i++) {
            a = (a * 3) ^ (a << 3);

            if (a > __INT32_MAX__) {
                a >>= timer;
                break;
            }
        }
        
    } else if (!hasSeed) {
        setSeed(defaultSeeds[timer]);
        return random();
    }

    return (a < 0) ? -(a) : a;    
}
