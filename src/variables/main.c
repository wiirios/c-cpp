#include <stdio.h>
#include <stdbool.h>

/* global variables */
int a = 10;
int length = 0;

/* const variable */
const int z = 10;

/* extern variable from extern.c */
extern int p;

/* its wrong */
/* char str = "hello"; */
/* its need to be an array */
const char str[] = "Hello"; /* the size of the string is determined by the compiler automatically */
/* OR */
const char str2[] = {'H', 'e', 'l' , 'l', 'o', '\0'}; /* the '\0' is a null character*/

// const volatile unsigned char *port = 0x30;

int funcInt () {
    /* the keyword 'auto' is not necessary */
    /* auto int x; */
    int x;

    x = 10;
    return x;
}

int funcIntIncrement() {
    static int i = 0;
    i++;

    return i;
}

/*
    
    will return 1 (true) if 's' contains 'c' or 0 (false) if not contains

*/
int findChar(const char *s,const char c) {
    while (*s) {
        if (*s == c) return true; 
        else s++;
    }

    return false;
}

bool isTrue() {
    bool b = true; /* <stdbool.h> */
    return b;
}

int main() {
    // Format specifiers define the type of data 
    // to be printed on standard output. 
    // You need to use format specifiers whether you're printing 
    // formatted output with printf() or accepting input with scanf().
    // printf("%d", funcInt()); // the '%d' is for a decimal integer (assumes base 10)
    
   // printf("%d\n", findChar("hello", 'w'));
   // printf("%s\n", str2);
    printf("%d", p);

    return 0;
}