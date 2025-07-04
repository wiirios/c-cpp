#ifndef STRING_H
#define STRING_H

#define END '\0'
#define MAX 1024

typedef struct string string_t;

string_t *init(const char * content);
string_t *string_copy(string_t *string);

size_t string_size(string_t *string);

int fatal(char *msg);
int string_compare(string_t *string, string_t *another_string);
int string_compare_ignore_case(string_t *string, string_t *another_string);
int string_span(string_t *string, string_t *another_string);
int char_occurence(string_t *string, unsigned int chr);
int is_empty(string_t *string);
int content_equals(string_t *string, char *char_sequence, size_t char_sequence_size);
int content_equals_ignore_case(string_t *string, char *char_sequence, size_t char_sequence_size);
int ends_with(string_t *string, char *char_sequence, size_t char_sequence_size);

char *char_at(string_t *string, unsigned int index);
char *content(string_t *string);

void free_string(string_t *string);
// !!!
// void string_concat(string_t *string, string_t *another_string);
// void replace(string_t *string);
// void remove_last(string_t *string);
void to_upper(char *chr);
void to_lower(char *chr);
// void remove_at(string_t *string, unsigned int index);

#endif