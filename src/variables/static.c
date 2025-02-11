#include <stdio.h>

int getStaticNumber() {
    static int log = 0;
    log++;

    return log;
}

int getNonStaticNumber() {
    int log = 0;
    log++;

    return log;
}

int main() {
    printf("%d\n", getStaticNumber()); /* 1 */
    printf("%d\n", getStaticNumber()); /* 2 */
    printf("%d\n", getStaticNumber()); /* 3 */

    printf("%d\n", getNonStaticNumber()); /* 1 */ 
    printf("%d\n", getNonStaticNumber()); /* 1 */
    printf("%d\n", getNonStaticNumber()); /* 1 */ 
}