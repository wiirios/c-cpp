#include "core.h"
#include "mathematica.h"

int main() {
   int num = 399948;
   const char ch[] = "1234";

   srand(time(NULL));
   long seed = rand() % 100 + 1;

   // printf("%d\n", seed);
   setSeed(seed);

   printf("%1.2f\n", pow(1, 457));
   printf("%ld\n", random() % 10);
   printf("%d\n", (int) root(E));
   printf("%d\n", reverse(num));
   int sumAfterValueOf = valueof(&ch[0]);

   printf("%d\n", sumAfterValueOf + 1);
   printf("%d\n", sum(3, 1, 2, 3));

   printf("%d\n", num);
   reverse_num(&num);
   printf("%d\n", num);

   removeSeed();

   return 0;
}