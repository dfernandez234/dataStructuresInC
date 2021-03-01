#ifndef Q
#include<stdio.h>
#include<stdlib.h>

typedef struct Q{
    int data;
    struct Q* front;
    struct Q* rear;
    struct Q* next;
}qn;

typedef qn* qNPtr;

void enqueue(qNPtr *q, int val){
    qNPtr newNode = (qn*)malloc(sizeof(qn));
    newNode->data = val;
    newNode->next = NULL;
    if((*q)->front == NULL){
        (*q)->front = newNode;
        (*q)->rear = newNode;
    }else{
        (*q)->rear->next = newNode;
        (*q)->rear = newNode;
    }
}

int dequeue(qNPtr *q){
    qNPtr del;
    if((*q)->front == NULL){
        return -100;
    }else{
        del = (*q)->front;
        (*q)->front = (*q)->front->next;
        return(del->data);
        free(del);
    }
}

int isEmptyQ(qNPtr Q){
    if(Q->front == NULL){
        return 1;
    }else{
        return 0;
    }
}

void displayQ(qNPtr Q){
    qNPtr curr = Q->front;
    while (curr!=NULL){
        printf("%d -- ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}



#define Q
#endif