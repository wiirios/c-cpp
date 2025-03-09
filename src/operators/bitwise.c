#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LENGTH 6

void decToBinary(int number) { 
    char result[32];
    int i = 0;
    size_t length = 0;

    while (number > 0) {
        result[i] = (number % 2) + '0';

        number = number / 2;
        i++;
    }

    result[i] = '\0';
    length = strlen(result);
    
    for (int j = i - 1; j >= 0; j--) printf("%c", result[j]);
}

int countBits(int number) {
    int count = 0;
    while (number) {
        if (number & 1) count++;
        number >>= 1;
        /* each loop he move the 1 to the rigth */
    }

    return count;
}

int findMissing(int array[], int k) {
    int missing = 0;

    for (int i = 0; i < k; i++) missing ^= i;

    for (int i = 0; i < k - 1; i++) missing ^= array[i]; 

    return missing;
}

bool isTheSame(int number1, int number2) {
    return (-(~ (number1 & number2) + 1)) == number1;
}

int main() {
    int array[] = {0, 1, 2, 3, 5};

    printf("%d\n", countBits(637));
    printf("%d\n", isTheSame(100, 100));
    printf("%d", findMissing(array, LENGTH));

    return 0;
}
