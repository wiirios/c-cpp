#include <stdio.h>

void *max(void *a, void *b) {
    if (a > b) return a;

    return b;
}

void *echo(void *data) {
    return data;
}

void print_value(void *ptr, char type) {
    switch (type) {
        case 'i':
            printf("Int: %d\n", *(int *)ptr);
            break;
        case 'f':
            printf("Float: %.2f\n", *(float *)ptr);
            break;
        case 'c':
            printf("Char: %c\n", *(char *)ptr);
            break;
        default:
            printf("Unknown type.\n");
    }
}

int main() {
    int x = 10;
    int a = 10;
    float b = 3.14f;
    char c = 'X';

    void *y = (int*) x;

    printf("%d\n", y);

    printf("%d\n", max((int*) 30, (int*) 100));
    printf("%c\n", max((char*) 'z', (char*) 'k'));

    print_value(&a, 'i');
    print_value(&b, 'f');
    print_value(&c, 'c');

    printf("%d\n", echo((int*) 55));

    /*
    In this context, 'void' doesn't literally mean "nothing" instead, it represents a generic or
    unspecified type, used when a variable or function doesn't have (or need) a defined data type.

    e.g:

        void free(void *);

    The 'free' function takes a 'void pointer' because it needs to be able to free memory allocated 
    for any data type, without knowing the exact type.
    The 'void *' allows this flexibility, since it can point to any kind of data.

    void *malloc(size_t size);

    The 'malloc' function returns a 'void pointer' because it allocates a block of memory 
    without knowing what type of data will be stored in it. This allows the function to be 
    used with any data type — the returned pointer can later be cast to the appropriate type.

    int *numbers = (int *)malloc(10 * sizeof(int));

    Here, 'malloc' allocates enough memory for 10 integers, and the 'void *' it returns is
    cast to 'int *' to be used as a pointer to integers.
    */

    return 0;
}
