//header file to operate on a stack using linked list

#ifndef stackH
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}n;

typedef n* nodePtr;

void push(int val, nodePtr *top){
    nodePtr newNode = (n*)malloc(sizeof(n));
    if (newNode==NULL){
        printf("Stack Overflow");
    }else{
        newNode->next = *top;
        newNode->val = val;
        *top = newNode;
    }
}

void pop(nodePtr *top){
    nodePtr pop;
    if(top==NULL){
        printf("Stack Underflow\n");
    }else{
        pop = *top;
        *top = (*top)->next;
        free(pop);
    }
}

int isEmpty(nodePtr top){
    if(top==NULL){
        return 1;
    }else{
        return 0;
    }
}


void display(nodePtr top){
    nodePtr curr = top;
    char cur;
    while (curr!=NULL){
        cur = curr->val;
        printf("%c",cur);
        curr = curr->next;
        printf("\n");
    }
}

#define stackH
#endif