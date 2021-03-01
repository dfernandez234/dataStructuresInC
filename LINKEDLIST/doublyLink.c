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
}

void insert(nodePtr *head, int pos, int val){
    nodePtr curr = *head, prev;
    nodePtr newNode = (n*)malloc(sizeof(n));
    newNode->data = val;    
    if(pos==0){
        newNode->next = *head;  
        (*head)->prev = newNode;
        *head = newNode;
    }else{
        for (int i = 0; i < pos; i++){
            prev = curr; 
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
        newNode->prev = prev;
        curr->prev = newNode;
    }
}

void delete(nodePtr *head, int pos){
    nodePtr curr = *head, prev;
    if(pos==0){
        *head = curr->next;
        (*head)->prev = NULL;
        free(curr);
    }else{
        for (int i = 0; i < pos-1; i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        (curr->next)->prev = prev;
        free(curr);
        curr = prev->next;       
    }
}

void reverse(nodePtr *head){
    nodePtr curr = *head, prev, next;
    while (curr!=NULL){
        prev = curr->prev;
        next = curr->next;
        curr->prev = next;
        curr->next = prev; 
        curr = next;
    }
    *head = prev->prev;
}

void display(nodePtr head){
    nodePtr curr = head, prev;
    while (curr!=NULL){
        printf("%d->",curr->data);
        prev = curr;
        curr = curr->next;
    }
    printf("\n");
    while (prev!=NULL){
        printf("%d->",prev->data);
        prev = prev->prev;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int A[8] = {1,2,3,4,5,6,7,8};
    int *ptrA = A;
    size_t n = sizeof(A)/sizeof(A[0]);
    nodePtr headPtr = malloc(sizeof(n)); //pointer of type struct
    createList(ptrA,n,headPtr);  
    insert(&headPtr,0,10);
    insert(&headPtr,4,10);
    display(headPtr); 
    printf("\n");
    reverse(&headPtr);
    display(headPtr);
    return 0;
}
