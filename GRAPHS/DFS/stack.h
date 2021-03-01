#ifndef stack
#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int data;
    struct stack *top;
    struct stack *next;
}st;

typedef st* stNPtr;

void push(stNPtr *stack, int val){
    stNPtr newNode = (st*)malloc(sizeof(st));
    newNode->data = val;
    newNode->next = NULL;
    if ((*stack)->top==NULL){
        (*stack)->top = newNode;
    }else{
        newNode->next = (*stack)->top;
        (*stack)->top = newNode;
    }
}

int pop(stNPtr *stack){
    stNPtr popP;
    if ((*stack)->top == NULL){
        return -1;
    }else{
        popP = (*stack)->top;
        (*stack)->top = (*stack)->top->next;
        return(popP->data);
        free(popP);
    }    
}

int isEmptyS(stNPtr stack){
    if (stack->top == NULL){
        return 1;
    }else{
        return 0;
    } 
}

void displayS(stNPtr Stack){
    stNPtr curr = Stack->top;
    int cur;
    while (curr!=NULL){
        cur = curr->data;
        printf("%d",cur);
        curr = curr->next;
        printf("\n");
    }
}

#define stack
#endif