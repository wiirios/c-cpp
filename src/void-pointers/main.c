#include <stdio.h>
#include <stdlib.h>

void *max(void *a, void *b) {
    if (a > b) return a;

    return b;
}

void *echo(void *data) {
    return data;
}

typedef enum {
    TY_CHAR,
    TY_INT,
    TY_UNSL
} type_t;

typedef struct stack
{
    void *data;
    size_t size;
    type_t type;
} stack_t;

stack_t *create(size_t size, type_t type) {
    stack_t *stack;
    size_t size_ = 0;

    if (type == TY_CHAR) size_ = size * sizeof(char);
    else if (type == TY_UNSL) size_= size * sizeof(unsigned long long);
    else size_ = size * sizeof(int);

    // stack = (stack_t*) malloc(sizeof(stack_t));
    stack->data = malloc(sizeof(size_));
    stack->size = size;
    return stack;
}

void add(stack_t *stack, void *data) {

    // if (stack->type == TY_INT) (

    // stack->data[0] = data;
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

    printf("Size of int: %d\n", sizeof(int)); // 4
    printf("Size of char: %d\n", sizeof(char)); // 1

    stack_t *stack;

    /* 
        casting! 
        int = (int *)
        char = (char *)

        ...
    */
    stack = create(10, TY_CHAR);
    /* oh */
    // ((int*) stack->data)[0] = 1;

    ((char*) stack->data)[0] = 'A';
    ((char*) stack->data)[1] = 'B';
    ((char*) stack->data)[2] = 'C';

    // ((int*) stack->data)[1] = 5;

    // printf("%d\n", ((int*) stack->data)[0]);
    // printf("%d\n", ((int*) stack->data)[1]);

    for (int i = 0 ; i < stack->size; i++) printf("%c\n", ((char*) stack->data)[i]);

    printf("%d\n", sizeof(unsigned long long));

    stack_t *stack_2;
    stack_2 = create(3, TY_INT);
    
    ((int*) stack->data)[0] = 900;
    ((int*) stack->data)[1] = 500;
    ((int*) stack->data)[2] = 200;

    for (int i = 0 ; i < stack_2->size; i++) printf("%d\n", ((int*) stack_2->data)[i]);

    free(stack);
    free(stack->data);

    free(stack_2);
    free(stack_2->data);
    return 0;
}
