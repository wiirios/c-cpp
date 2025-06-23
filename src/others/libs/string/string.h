#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define END '\0'
#define MAX 1024

typedef struct string {
    char *content;
    int size;
} string_t;

string_t *init(string_t *string);
string_t *string_copy(string_t *string);

int fatal(char *msg);
int string_compare(string_t *string, string_t *another_string, unsigned int limit);
int string_span(string_t *string, string *another_string);
int char_occurence(string_t *string, unsigned int chr);
int string_length(string_t *string);
int is_empty(string_t *string);

char *char_at(string_t *string);

void free(string_t *string);
// !!!
void string_concat(string_t *string, string_t *another_string);
void replace(string_t *string);

#endif