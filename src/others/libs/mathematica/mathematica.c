#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

static long *sseed;
bool hasSeed = false;

/*
    127, 508, 1016, 8128, 130047, 166465, 2663440, 15981641
*/

static int defaultSeeds[] = {
    0x7f, 0x1fc, 0x3f8, 0x1fc0, 0x1FBFF, 0x28A41, 0x28a410, 0xF3DC49
};

void fatal(char *msg) {
    printf("Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

/* well.. */

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

/* 1 for true and 0 for false */

int isgreater(int a, int b) {
    return (a > b) ? true : false;
}

int isgreaterorequal(int a, int b) {
    return (a >= b) ? true : false;
}

int isless(int a, int b) {
    return (a < b) ? true : false;
}

int islessorequal(int a, int b) {
    return (a <= b) ? true : false;
}

// int reverse(int a[]) {


//     return 0;
// }

double pow(double a, double b) {
    int c = a;

    for (int i = 1; i < b; i++) a *= c;

    return a;
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
