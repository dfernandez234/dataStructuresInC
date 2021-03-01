#ifndef linkedlist
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; 
    struct Node* next;  
}ln;

typedef ln* lNodePtr;

void sortedInsert(lNodePtr *head, int key){
    lNodePtr newNode = (ln*)malloc(sizeof(ln));
    lNodePtr curr = *head;
    lNodePtr prev = NULL;
    newNode->next = NULL;
    newNode->data = key;
    if ((*head) == NULL){
        (*head) = newNode;
    }else{
        while (curr->data < key && curr->next!=NULL){
            prev = curr;
            curr = curr->next;
        }
        if(curr == *head && curr->data > key){
            newNode->next = (*head);
            *head = newNode;
        }
        else if(curr->next == NULL){
            curr->next = newNode;
        }
        else{
            prev->next = newNode;
            newNode->next = curr;
        }         
    }
}

void display(lNodePtr *head){
    lNodePtr curr = *head;
    while (curr!=NULL){
        printf("%d->",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

#define linkedlist
#endif