#include <stdio.h>
#include <string.h>

/* 2 */
#define NELEMS(A) sizeof(A) / sizeof(A[0]) 

/* 3 */
/* ORIGINAL: #define DOUBLE(X) 2*X */
#define DOUBLE(X) (2*(X)) /* fixed */

/* 4 */
/* ORIGINAL: #define AVG(X,Y) (X-Y) / 2 */
#define AVG(X,Y) (X+Y) / 2 /* fixed */
#define AREA(X,Y) (X) * (Y) /* is correct */

/* 5 */
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

/* 6 */
#define DISP(A,B)

#undef printf
#define print(A,B) printf()

int main() {
    char array[] = "Apple";
    char array_2[4];
    strcpy(array_2, "asd");
    int i = 0;

    printf("%d\n", NELEMS(array));
    printf("%d\n", DOUBLE(1+2));
    printf("%d\n", 4/DOUBLE(2));
    printf("%d\n", AREA(30, 20));
    printf("%d\n", AVG(2+3, 4+5));
    printf("%c\n", TOUPPER('j'));

    return 0;
}
