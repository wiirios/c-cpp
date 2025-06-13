#include <stdio.h>
#include <math.h>

void addDigits(int num) {
    int i = 0;
    int hasSpl = 0;
    int n = num;
    int arr[] = {0, 0};

    while (1) {
        arr[i] = arr[i] * 10 + n % 10;
        n = n / 10;

        n = arr[0] + arr[1];

        if (n <= 10 && hasSpl) break;
        else {
            i = 0;
            arr[0] = 0;
            arr[1] = 0;
            hasSpl = 0;
        }

        hasSpl = 1;
        i++;        
    }

    printf("%d\n", arr[0] + arr[1]);
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);

}

int main() {
    int n = 38;
    // printf("%d\n", addDigits(n));
    // printf("%d\n", n);
    addDigits(38);

    return 0;
}