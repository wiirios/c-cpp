#include <stdio.h>
#include <stdbool.h>

int main() {
    bool b = !(4 + 4 > 5);

    printf("%s", b ? "true" : "false");

    return 0;
}