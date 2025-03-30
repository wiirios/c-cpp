#include <stdio.h>
#define DEBUG 1
#pragma message("Compiling... Please wait!")

/*
C:>gcc macrosdirectives.c
macrosdirectives.c:3:9: note: #pragma message: Compiling... Please wait!
#pragma message("Compiling... Please wait!")
        ^~~~~~~
*/

int main() {
    int a = 10;
    int b = 4;
    
    printf("oi\n");
    #if DEBUG
        printf("some test here");
    #endif

    /* OR */

    /*
        since "defined" tests only whether DEBUG is defined or not, it's not necessary to give DEBUG value

        #define DEBUG
    */
    #if defined DEBUG
        printf("some test here");
    #else
        printf("hmm");
    #endif

    #if defined _WIN32
        printf("Windows");
    #elif defined LINUX
        printf("Linux");
    #endif    
    
    return 0;
}

