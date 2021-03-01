#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data; 
    struct node *prev; 
    struct node *next;
}n;

typedef struct node* nodePtr;

void createList(int *Array, size_t size, nodePtr head){
    int *const end = Array + size;
    nodePtr curr;
    //first node
    head->data = *Array;
    head->next = NULL;
    head->prev = NULL;
    Array = Array+1;
    curr = head;
    while (Array<end){
        nodePtr newNode = (n*)malloc(sizeof(n));
        newNode->data = *Array;
        curr->next = newNode;
        newNode->next = NULL;
        newNode->prev = curr;
        curr = newNode;
        Array++;
    }
    curr->next = head;
    head->prev = curr;
}

void display(nodePtr head){
    nodePtr curr = head;
    nodePtr prev;
    while(curr->next!=head){
       printf("%d->",curr->data);
       prev = curr;
       curr = curr->next;
    }
    printf("%d->",curr->data);
    printf("\n");
    while (prev->prev!=curr){
        printf("%d->",prev->data);
        prev = prev->prev;
    }
    printf("%d",(prev->data));
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int A[9] = {1,2,3,4,5,6,7,8,9};
    int *ptrA = A;
    size_t n = sizeof(A)/sizeof(A[0]);
    nodePtr headPtr = malloc(sizeof(n)); //pointer of type struct
    createList(ptrA,n,headPtr);  
    display(headPtr);
    return 0;
}
