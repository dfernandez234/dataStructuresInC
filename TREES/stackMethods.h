//linked stack methods for iterative tree traversal implementation
#ifndef stackMethods
#include<stdio.h>
#include<stdlib.h>
#include"binTree.h"

typedef struct SNode{
    TNodePtr add;
    struct SNode *next;
    struct SNode *Top;
}SN;

typedef SN * SNodePtr;

void push(SNodePtr *Stack, TNodePtr Add){
    //check if stack is full
    SNodePtr newNode = (SN*)malloc(sizeof(SN));
    if(newNode == NULL){
        printf("Stack Overflow \n");
        exit(1);
    }
    newNode->add = Add;
    newNode->next = NULL;
    //first element
    if((*Stack)->Top == NULL){
        ((*Stack)->Top) = newNode;
    }else{
        newNode->next = (*Stack)->Top;
        ((*Stack)->Top) = newNode;
    }
}


TNodePtr pop(SNodePtr *Stack){
    SNodePtr popped;
    if((*Stack)->Top == NULL){
        printf("Stack Underflow\n");
        return(0x00);
    }else{  
        popped = (*Stack)->Top;
        (*Stack)->Top = (*Stack)->Top->next;
        return popped->add;
        free(popped);
    }
}

void displayS(SNodePtr Stack){
    SNodePtr curr = Stack->Top;
    TNodePtr cur;
    while (curr!=NULL){
        cur = curr->add;
        printf("%p",cur);
        curr = curr->next;
        printf("\n");
    }
}

int isEmptyS(SNodePtr Stack){
    if(Stack->Top == NULL){
        return 1;
    }else{
        return 0;
    }
}

#define stackMethods
#endif