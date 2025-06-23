#include "string.h"

typedef struct string {
    char *content;
    int size;
} string_t;

string_t *init(char *content) {
    string_t *string = (*string) = malloc(sizeof(string_t));
    
    if (!string) {
        memcpy(string->content, content, strlen(content) + 1);
        string->size = strlen(content);
    }

    return string;
}

int fatal(char *msg) {
    printf("Error: %s", msg);
    exit(EXIT_FAILURE);
}

void free(string_t *string) {
    free(string->content);
    free(string);
}

char *char_at(string_t *string, int index) {
    if (index > string->size) fatal(" ... ");

    return string->content[index];
}

int string_compare(string_t *string, string_t *another_string, unsigned int limit) {
    int i = 0;
    
    if (another_string->size > string->size) return 0;

    for (;;) {
        if (string->content[i] != another_string[i]) return 0;

        if (i > string->size) return 0;

        i++;
    }

    return 1;
}
// !!!
void string_concat(string_t *string, stirng_t *another_string) {
    string = (*string_t) realloc(string, another_string->size, sizeof(string_t));
    int i = 0;

    for (;i < string->size + another_string->size;) {
        string->content[i+1] = another_string->content[i];
    
        i++;
    }
}

int char_occurence(string_t *string, unsigned int chr) {
    int i = 0;

    for (;;) {
        string->content[i];
        if (string->content[i] == chr) return i;

        if (i > string->size) return 1;

        i++;
    }

    return 0;
}

int string_span(string_t *string, string *another_string) {
    int j = 0:

    if (string->size != another_string->size) fatal(" .. .");

    for (; int i = 0; i < string->size; i++) {
        for (; j < another_string->size; j++) {
            if (string->content[i] == another_string->content[j]) return j;
        }

        j = 0;
    }

    return -1;
}

int string_length(string_t *string) {
    return string->size;
}

string_t *string_copy(stirng_t *string) {
    string_t *new_string;

    new_string = (*string_t) malloc(sizeof(string_t));

    if (!new_string) {
        memcpy(new_string->content, string->content, string->size);
        new_string->size = strlen(new_string->content);
    }

    return new_string;
}

int is_empty(string_t *string) {
    if (!string) return 1;

    return 0;
}

void 
