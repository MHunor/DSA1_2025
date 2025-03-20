//
// Created by madarasz.hunor on 3/20/2025.
//

#ifndef LAB_05_ARRAY_H
#define LAB_05_ARRAY_H
#define INVALID_VALUE 99999
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int capacity;
    int size;
    int *elements;
}IntArray;
/**
* Allocates memory for an array with a given capacity
* @param capacity
* @param pArray
*/
void createIntArray(int capacity, IntArray* pArray);
/**
* Prints all items in the array
* @param array
*/

void printArray(IntArray array);
/**
* Check whether the array is full or not
* @param array
* @return true/false
*/
bool isFull(IntArray array);
/**
* Check whether the array is empty or not
* @param array
* @return true/false
*/
bool isEmpty(IntArray array);
/**
* Returns an item at a given position if the position is correct
* @param array
* @param position
* @return item at position/INT_MIN
*/
int getItemAt(IntArray array, int position);
/**
* Inserts an item at the beginning of the array
* @param pArray
* @param item
*/
void insertFirst(IntArray* pArray, int item);
/**
* Inserts an item at the end of the array
* @param pArray
* @param item
*/
void insertLast(IntArray* pArray, int item);
/**
* Inserts an item at at a given position if the position is correct
* @param pArray
* @param item
*/
void insertAt(IntArray* pArray, int position, int item);
/**
* Deletes an item at a given position if the position is correct
* @param pArray
* @param position
*/
void deleteItemAt(IntArray* pArray, int position);
/**
* Searches for an item in the array
* @param pArray
* @param item
* @return position/-1
*/
int search(IntArray pArray, int item);

/**
* Updates an item at a given position with a new item if the position is
correct
* @param pArray
* @param position
* @param newItem
* @return true if update is successful, otherwise false
*/
bool update(IntArray* pArray, int position, int newItem);
/**
* Deallocates memory for array
* @param pArray
*/
void deallocateIntArray(IntArray *pArray);



#endif //LAB_05_ARRAY_H
