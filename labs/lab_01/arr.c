//
// Created by madarasz.hunor on 2/27/2025.
//

#include "arr.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float minimum(float number1, float number2, float number3) {
    float min = number1;
    if (number2 < min) min = number2;
    if (number3 < min) min = number3;
    return min;
}

float* allocateMemoryForArray1(int n) {
    return (float*)malloc(n * sizeof(float));
}

void allocateMemoryForArray2(int n, float **dpArray) {
    *dpArray = (float*)malloc(n * sizeof(float));
}

void printArray(int n, float *pArray, const char *output) {
    FILE *file = fopen(output, "w");
    if (file == NULL) {
        printf("Hiba a fajl megnyitasakor.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%.2f ", pArray[i]);
    }
    fclose(file);
}

void deallocateMemoryForArray(float **dpArray) {
    free(*dpArray);
    *dpArray = NULL;
}

void fillWithRandomNumbers(int n, float *pArray, float start, float end) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        pArray[i] = start + ((float)rand() / RAND_MAX) * (end - start);
    }
}