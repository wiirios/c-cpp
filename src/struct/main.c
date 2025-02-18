#include <stdio.h>

struct addre
{
    char street[30];
    char city[30];
    unsigned long zip;
};

int main() {
    /* designated initializer */

    /*
        It provides a way of explicitly initialising struct members. For e.g.
        
        .street = "R.39", .city = "NY" ...

    */
    struct addre addre_info = {.street = "R.39", .city = "NY", .zip = 22};

    return 0;
}