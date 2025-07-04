#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "string.h"

int main(int argc, char* argv[]) {
    string_t *string;
    string = init("Hello");

    char char_sequence[] = "ello";

    printf("string size: %d\n", string_size(string));
    printf("is empty: %d\n", is_empty(string));

    printf("content equals: %d\n", content_equals(string, &char_sequence[0], strlen(char_sequence)));
    printf("content equals ignore case: %d\n", content_equals_ignore_case(string, &char_sequence[0], strlen(char_sequence)));
    printf("ends with: %d\n", ends_with(string, &char_sequence[0], strlen(char_sequence)));

    printf("char at index 0: %c\n", *char_at(string, 0));
    printf("string content: %s\n", content(string));

    string_t *another_string;
    another_string = init("hello");

    printf("string compare: %d\n", string_compare(string, another_string));
    printf("string compare ignore case: %d\n", string_compare_ignore_case(string, another_string));

    free_string(string);
    free(another_string);
    return 0;
}
