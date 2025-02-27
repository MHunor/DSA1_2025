//
// Created by madarasz.hunor on 2/27/2025.
//

#ifndef ARR_H
#define ARR_H

float minimum(float number1, float number2, float number3);
float* allocateMemoryForArray1(int n);
void allocateMemoryForArray2(int n, float **dpArray);
void printArray(int n, float *pArray, const char *output);
void deallocateMemoryForArray(float **dpArray);
void fillWithRandomNumbers(int n, float *pArray, float start, float end);

#endif //ARR_H
