#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "string.h"

typedef struct string {
    char *content;
    size_t size;
} string_t;

string_t *init(const char *content) {
    string_t *string = (string_t*) malloc(sizeof(string_t));
    
    if (string == NULL) fatal("memory malloc");

    string->size = strlen(content);

    string->content = (char*) malloc((string->size) + 1);

    if (string->content == NULL) fatal("memory malloc for content");

    memcpy(string->content, content, strlen(content) + 1);    
    
    return string;
}

int fatal(char *msg) {
    printf("Error: %s", msg);
    exit(EXIT_FAILURE);
}

void free_string(string_t *string) {
    free(string->content);
    free(string);
}

char *char_at(string_t *string, unsigned int index) {
    if (index > string->size) fatal(" ; ");

    return &string->content[index];
}

int string_compare(string_t *string, string_t *another_string) {
    int i = 0;
    
    if (another_string->size > string->size) return 0;

    for (;;) {
        if (string->content[i] != another_string->content[i]) return 0;

        if (i > string->size) break;

        i++;
    }

    return 1;
}
// !!!
// void string_concat(string_t *string, stirng_t *another_string) {
//     string = (*string_t) realloc(string, another_string->size, sizeof(string_t));
//     int i = 0;

//     for (;i < string->size + another_string->size;) {
//         string->content[i+1] = another_string->content[i];
    
//         i++;
//     }
// }

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

int string_span(string_t *string, string_t *another_string) {
    int j = 0;

    if (string->size != another_string->size) fatal(" .. .");

    for (int i = 0; i < string->size; i++) {
        for (; j < another_string->size; j++) {
            if (string->content[i] == another_string->content[j]) return j;
        }

        j = 0;
    }

    return -1;
}

size_t string_size(string_t *string) {
    return string->size;
}

string_t *string_copy(string_t *string) {
    string_t *new_string;

    new_string = (string_t*) malloc(sizeof(string_t));

    if (!new_string) {
        memcpy(new_string->content, string->content, string->size);
        new_string->size = strlen(new_string->content);
    }

    return new_string;
}

int is_empty(string_t *string) {
    if (!string || string->size == 0) return 1;

    return 0;
}

char *content(string_t *string) {
    if (!string) fatal(";");

    return string->content;
}

// !!
// void remove_last(string_t *string) {
//     if (!string || string->size == 0) fatal(";;");

//     string->content[string->size] = END;

//     string->size--;
// }

// void remove_at(string_t *string, unsigned int index) {
//     if (!last || string->size == 0) fatal(".");


// }

int string_compare_ignore_case(string_t *string, string_t *another_string) {
    int i = 0;

    if (string->size > another_string->size) return 0;

    for (;;) {
        if (tolower(string->content[i]) != tolower(another_string->content[i])) return 0;
        
        if (i > string->size) break;

        i++;
    }

    return 1;
}

int content_equals(string_t *string, char *char_sequence, size_t char_sequence_size) {
    int i = 0;
    int j = 0;

    if (!string) fatal("null string");

    if (string->size < char_sequence_size) fatal("string size < char sequence");

    for (; i < string->size; i++) {
        
        if (string->content[i] == char_sequence[j]) {
            for (; j < char_sequence_size; j++) {
                if (string->content[i] != char_sequence[j]) return 0;

                i++;
            }
            return 1;
        }
    }

    return 0;
}

int content_equals_ignore_case(string_t *string, char *char_sequence, size_t char_sequence_size) {
    int i = 0;
    int j = 0;

    if (!string) fatal("null string");

    if (string->size < char_sequence_size) fatal("string size < char sequence");
    
    for (; i < string->size; i++) {

        if (tolower(string->content[i]) == tolower(char_sequence[j])) {
            for (; j < char_sequence_size; j++) {
                if (tolower(string->content[i]) != tolower(char_sequence[j])) return 0;
            
                // if (iscntrl(char_sequence[j]) == 0) goto err_control_char;

                i++;
            }

            return 1;
        }
    }

    // err_control_char:
        // fatal(";;");
        // return fatal(";;");
        // return 0;

    return 0;
}

int ends_with(string_t *string, char *char_sequence, size_t char_sequence_size) {
    int i = string->size - char_sequence_size;
    
    if (!string) fatal("null string");

    if (string->size < char_sequence_size) fatal("string size < char sequence");

    for (; i < string->size; i++) {
        if (string->content[i] != char_sequence[i]) return 0;
    
        // if (iscntrl(char_sequence[i]) == 0) goto err_control_char;
    }

    // err_control_char:
        // return 0;

    return 1;
}

void to_upper(char *chr) {
    // chr + 62;
    *chr = toupper((int) chr);
}

void to_lower(char *chr) {
    *chr = tolower((int) chr);
}
