#include <stdio.h>

#define PRINT(n) printf(n);
#define STR_LEN 100
#define SIZE 256
#define TWO_PI (2*3.14159) /* needs parentheses */
#define ECHO(n) (gets(n), puts(n));
#define CHECK_DIVISOR(divisor) if (divisor == 0) printf("Error at line %d", __LINE__); /* defined macro */
#define CHECK_DIVISOR_2(divisor) if (divisor == 0) \
                                printf("Error at line %d", __LINE__);  /* we can use "\" for break line "*/

/*
    __func__ returns the name of function e.g: main,
    is useful for debugging 
*/
#define FUNCTION_CALLED() printf("%s called\n", __func__); /* __func__ returns the name of function e.g: main, */

int BUFFER_SIZE;

void generic_function(void) {
    FUNCTION_CALLED()
}

int main() {
    // char STRING_[STR_LEN] = "Hello";
    char STRING_[STR_LEN];

   generic_function(); /* out: 
   
   generic_function called 
   
   */
    
    /* before preprocessing */
    // PRINT(s);

    /* after preprocessing */
    // printf(s);;

    /* same happens here */

    // if (BUFFER_SIZE > SIZE)
    //      puts("Error: SIZE exceeded")

    //  if (BUFFER_SIZE > 256)
    //      puts("Eri'or: SIZE exceeded")

    // The identifier BUFFER SIZE and the string "Error: SIZE exceeded"
    // weren’t affected by preprocessing, even though both contain the word SIZE.

    // printf("%1.2f\n", 360/TWO_PI);

    // ECHO(STRING_);

    // CHECK_DIVISOR_2(0);

    return 0;
}