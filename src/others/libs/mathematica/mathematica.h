#ifndef MATHEMATICA_H
#define MATHEMATICA_H

#define PI 3.14

double pow(double a, double b);
double root(double a);

int sum(int count, ...);
int max(int a, int b);
int min(int a, int b);
int random(void);
int is_greater(int a, int b);
int isgreaterorequal(int a, int b);
int is_less(int a, int b);
int islessorequal(int a, int b);
int reverse(int num);
int valueof(const char *ch);

void setSeed(long seed);
void removeSeed(void);
void fatal(char *msg);
void reverse_num(int* num);

#endif