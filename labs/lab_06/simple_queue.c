//
// Created by madarasz.hunor on 3/27/2025.
//

#include <string.h>
#include "simple_queue.h"


void createQueue(int capacity, Simple_Queue_t *queue) {
    queue->capacity=capacity;
    queue->rear=-1;
    queue->front=-1;
    queue->elements = (char**)calloc(capacity,sizeof(char*));
    if(!queue->elements){
        printf("MEMORY ERROR");
        exit(-1);
    }
}

void destroyQueue(Simple_Queue_t *queue) {
    free(queue->elements);
    queue->rear=-1;
    queue->front=-1;
    queue->capacity=0;
}

bool isFull(Simple_Queue_t queue) {
    if(queue.rear==queue.capacity-1)
        return 1;
    return 0;
}

bool isEmpty(Simple_Queue_t queue) {
    if(queue.front == -1)
        return 1;
    return 0;
}

void enqueue(Simple_Queue_t *queue, const char *item) {
    if (isFull(*queue)) {
        printf("Tele a sor\n");
        return;
    }
    if (isEmpty(*queue)){
        queue->front=0;
    }
    queue->rear++;
    queue->elements[queue->rear]=strdup(item);
}

char *dequeue(Simple_Queue_t *queue) {
    if (isEmpty(*queue)){
        printf("Ures a sor\n");
    }
    char* item = queue->elements[queue->front];
    if(queue->front==queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front++;
        return item;
    }

}

void display(Simple_Queue_t queue) {
    if(isEmpty(queue)){
        printf("Ures a sor\n");
        return;
    }
    else
        for(int i = queue.front;i<=queue.rear;i++){
            printf("%s",queue.elements[i]);
        }
    printf("\n");
}

char *peek(Simple_Queue_t queue) {
    if (isEmpty(queue)){
        return "";
    }
    return queue.elements[queue.front];
}
