#include <stdio.h>

#define FLAG_1 1
#define FLAG_2 2
#define FLAG_3 4

void permission(int flag) {
    if ((flag & FLAG_1) != 0) {
        printf("1st feature is enabled\n");        
    }

    if ((flag & FLAG_2) != 0) {
        printf("2nd feature is enabled\n");
    }
}

int main() {
    int flag = FLAG_1 | FLAG_2 | FLAG_3;

    permission(flag);

    flag = flag & ~FLAG_2; /* disable the 2nd feature */

    permission(flag);
}