//
// Created by madarasz.hunor on 3/20/2025.
//
#include "array.h"
void createIntArray(int capacity, IntArray *pArray){
    pArray->capacity=capacity;
    pArray->size=0;
    pArray->elements = (int*)calloc(capacity,sizeof(int));
    if(!pArray->elements){
        printf("MEMORY ERROR");
        exit(-1);
    }
}
void deallocateIntArray(IntArray *pArray){
    free(pArray->elements);
    pArray->size=0;
    pArray->capacity=0;
}

bool isFull(IntArray array){
    return array.size==array.capacity;
}
bool isEmpty(IntArray array){
    return array.size==0;
}
void printArray(IntArray array){
    if(isEmpty(array)){
        printf("Ures az array\n");
    }
    else
        for(int i =0;i<array.size;i++){
            printf("%d ",array.elements[i]);
        }
    printf("\n");
}
int getItemAt(IntArray array, int position) {
    if(position<0 || position>=array.size){
        return INVALID_VALUE;
    }
    return array.elements[position];
}

void insertFirst(IntArray* pArray, int item) {
    if (isFull(*pArray)) {
        printf("Tele az array\n");
    }
    else {
        for (int i = pArray->size; i > 0; i--) {
            pArray->elements[i] = pArray->elements[i - 1];
        }
        pArray->elements[0] = item;
        pArray->size++;
    }
}
void insertLast(IntArray* pArray, int item){
    if (isFull(*pArray)) {
        printf("Tele az array\n");
    }
    else {
        pArray->elements[pArray->size] = item;
        pArray->size++;
    }
}

void insertAt(IntArray* pArray, int position, int item){
    if(position<0 || position>pArray->size){
        printf("Rossz pozicio\n");
        return;
    }
    if (isFull(*pArray)) {
        printf("Tele az array\n");
        return;
    }
    for (int i = pArray->size; i > position; i--) {
        pArray->elements[i] = pArray->elements[i - 1];
    }
    pArray->elements[position] = item;
    pArray->size++;
}

void deleteItemAt(IntArray* pArray, int position){
    if(position<0 || position>pArray->size){
        printf("Rossz pozicio\n");
        return;
    }
    if(isEmpty(*pArray)){
        printf("Ures az array\n");
        return;
    }
    for (int i = position; i < pArray->size; i++) {
        pArray->elements[i] = pArray->elements[i + 1];
    }
    pArray->size--;
}
int search(IntArray pArray, int item){
    for (int i = 0; i < pArray.size; i++) {
        if(pArray.elements[i]==item) {
            return i;
        }
    }
    return -1;
}
bool update(IntArray* pArray, int position, int newItem){
    if(position<0 || position>pArray->size){
        return false;
    }
    pArray->elements[position]=newItem;
    return true;
}