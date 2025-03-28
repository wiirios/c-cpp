#include <math.h>
#include <stdio.h>

#undef sqrt
#define sqrt(x) ((x)>=0?sqrt(x):0)

int main() {
    printf("%1.2f\n", sqrt(-9.0));
    
    return 0;
}