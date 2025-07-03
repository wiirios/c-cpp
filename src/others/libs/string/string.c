#include "string.h"

typedef struct string {
    char *content;
    int size;
} string_t;

string_t *init(char *content) {
    string_t *string = (*string) = malloc(sizeof(string_t));
    
    if (string == NULL) fatal("memory malloc");

    memcpy(string->content, content, strlen(content) + 1);
    string->size = strlen(content);

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

char *char_at(string_t *string, unsigned int index) {
    if (index > string->size) fatal(" ; ");

    return string->content[index];
}

int string_compare(string_t *string, string_t *another_string, unsigned int limit) {
    int i = 0;
    
    if (another_string->size > string->size) return 0;

    for (;;) {
        if (string->content[i] != another_string[i]) return 0;

        if (i > string->size) break;

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

    for (int i = 0; i < string->size; i++) {
        for (; j < another_string->size; j++) {
            if (string->content[i] == another_string->content[j]) return j;
        }

        j = 0;
    }

    return -1;
}

int string_size(string_t *string) {
    return string->size;
}

string_t *string_copy(stirng_t *string) {
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
void remove_last(string_t *string) {
    if (!string || string->size == 0) fatal(";;");

    string->content[string->size] = END;

    string->size--;
}

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

    if (!string) return fatal(";;");

    if (string->size < char_sequence_size) return fatal(";;");

    for (; i < string->size; i++) {
        
        if (string->content[i] == char_sequence[i]) {
            for (; j < char_sequence_size; j++) if (string->content[j] != char_sequence[j]) return 0;

            return 1;
        }
    }

    return 0;
}

int content_equals_ignore_case(string_t *string, char *char_sequence, size_t char_sequence_size) {
    int i = 0;
    int j = 0;

    if (!string || string->size < char_sequence_size) return fatal(";;");
    
    for (; i < string->size; i++) {

        if (tolower(string->content[i]) == tolower(char_sequence[i])) {
            
            for (; j < char_sequence_size; j++) {
                if (tolower(string->content[j]) != tolower(char_sequence[j])) return 0;
            
                if (iscntrl(char_sequence[j]) == 0) goto err_control_char;
            }

            return 1;
        }
    }

    err_control_char:
        // fatal(";;");
        // return fatal(";;");
        return 0;

    return 0;
}

int ends_with(string_t *string, char *char_sequence, size_t char_sequence_size) {
    int i = string->size - char_sequence_size;

    if (!string || string->size < char_sequence_size) return fatal(" ;;");

    for (; i < string->size; i++) {
        if (string->content[i] != char_sequence[i]) return 0;
    
        if (iscntrl(char_sequence[i]) == 0) goto err_control_char;
    }

    return 1;
}

void to_upper(char *chr) {
    // chr + 62;
    *chr = toupper(ch);
}

void to_lower(char *chr) {
    *chr = tolower(chr);
}
