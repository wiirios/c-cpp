#include "string.h"

int main(int argc, char* argv[]) {
    string_t *string;
    string = init(";;");

    int x = 0;
    char char_sequence[] = "Teste";

    x = string_size(string);

    printf("%d", x);
    printf("%s", char_at(string, 0));

    remove_last(string);

    size_t char_sequence_size = sizeof(char_sequence) / sizeof(char);
    x = content_equals(string, &char_sequence[0], char_sequence_size);

    printf("%d", x);

    return 0;
}