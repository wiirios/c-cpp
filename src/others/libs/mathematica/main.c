#include "core.h"
#include "mathematica.h"

int main() {
   srand(time(NULL));
   long seed = rand() % 100 + 1;

   printf("%d\n", seed);
   setSeed(seed);

   printf("%1.2f\n", pow(C, D));
   printf("%ld\n", random() % 10);
   printf("%d\n", (int) root(E));
   printf("%d\n", reverse(F));
   
   removeSeed();

   return 0;
}