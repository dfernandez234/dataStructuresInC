//defining methods for creating binary tree using linked-list Queue

#ifndef queueMethods
#include<stdio.h>
#include<stdlib.h>

typedef struct TNode{
    struct TNode *lchild;
    struct TNode *rchild;
    int data;
}TN;

typedef struct QNode{
    //store addresses of Tree Nodes
    TN *add;
    struct QNode *next;
    struct QNode *front;
    struct QNode *rear;
}QN;

//Pointer toweards Tree Node
typedef TN* TNodePtr;

//pointer towards Q
typedef QN* QNodePtr;


void enqueue(QNodePtr *Q, TNodePtr add){
    //check if Q is full
    QNodePtr newElement = (QN*)malloc(sizeof(QN));
    if(newElement == NULL){
        printf("Stack Overflow\n");
        exit(1);
    }
    newElement->add = add;
    newElement->next = NULL;
    //check if it is the first element
    if((*Q)->front == NULL){
        (*Q)->front = newElement;
        (*Q)->rear = newElement;
    }else{
        (*Q)->rear->next = newElement;
        (*Q)->rear = newElement;
    }
}


TNodePtr dequeue(QNodePtr *Q){
    TNodePtr dq;
    //check if Q is empty
    if((*Q)->front == NULL){
        printf("Stack Underflow\n");
        exit(1);
    }else{
        dq = ((*Q)->front)->add;
        (*Q)->front = ((*Q)->front)->next;
        return dq;
        free(dq);
    }
}

int isEmptyQ(QNodePtr Q){
    if(Q->front == NULL){
        return 1;
    }else{
        return 0;
    }
}

void displayQ(QNodePtr Q){
    QNodePtr curr = Q->front;
    while (curr!=NULL){
        printf("%p -- ",curr->add);
        curr = curr->next;
    }
    printf("\n");
}

#define queueMethods
#endif