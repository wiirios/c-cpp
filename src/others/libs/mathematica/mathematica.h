#ifndef MATHEMATICA_H
#define MATHEMATICA_H

#define PI 3.14

double pow(double a, double b);
double root(double a);

int max(int a, int b);
int min(int a, int b);
int random(void);
// int isgreater(int a, int b);
int isgreaterorequal(int a, int b);
// int isless(int a, int b);
int islessorequal(int a, int b);
// int reverse(int a);
// int valueof(char *ch);

void setSeed(long seed);
void removeSeed(void);
void fatal(char *msg);

#endif