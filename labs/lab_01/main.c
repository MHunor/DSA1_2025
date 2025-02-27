#include <stdio.h>
#include "arr.h"
int main(void) {

    int n;
    do {
        printf("A tomb elemeinek szama: ");
        scanf("%d", &n);
    } while (n <= 0 || n % 2 == 0);

    float *arr = allocateMemoryForArray1(n);

    fillWithRandomNumbers(n, arr, 0.0, 1.0);


    printArray(n, arr, "output.txt");

    float first = arr[0];
    float middle = arr[n / 2];
    float last = arr[n - 1];

    float minValue = minimum(first, middle, last);
    printf("A legkisebb ertek: %.2f\n", minValue);

    deallocateMemoryForArray(&arr);

    return 0;



}
