#include<stdio.h>
#include<stdlib.h>

typedef struct nodes{
    int val; //value to be stored bu eacho node
    struct nodes* next; //pointer to the next element
}n;
typedef n* nodePtr;

void createList(int *Array, size_t size, nodePtr head){
    int *const end = Array + size;
    nodePtr prev;
    //set the head of the list
    head->val = *Array;
    Array +=1;
    head->next = NULL;
    prev = head;
    while (Array<end){
        nodePtr newNode = (n*)malloc(sizeof(n));
        newNode->val = *Array;
        newNode->next = NULL;
        prev->next = newNode;
        prev = newNode;
        Array +=1;
    }
    prev->next = head;
}


void insert(nodePtr *headPtr, int val, int pos){
    nodePtr newNode = (n*)malloc(sizeof(n));
    nodePtr current = *headPtr, prev;
    newNode->val = val;
    if (pos==0){
        while (current->next != *headPtr){
            current = current->next;
        }
        newNode->next = *headPtr;
        *headPtr = newNode; 
        current->next = *headPtr;
    }else{
        for (int i = 0; i < pos-1; i++){
            prev = current;
            current = current->next;
        }
        prev->next=newNode;
        newNode->next = current;
    }
}

void delete(nodePtr *headPtr, int pos){
    nodePtr current = *headPtr, prev;
    if (pos==0){
        prev = *headPtr;
        while (current->next != *headPtr){
            current = current->next;
        }
    *headPtr = prev->next;
    current->next = *headPtr;
    free(prev);
    }else{
        for (int i = 0; i < pos-1; i++){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current);
    }   
}

void dispCirc(nodePtr head){
    nodePtr curr = head;
    while(curr->next!=head){
       printf("%d->",curr->val);
       curr = curr->next;
    }
    printf("%d->",curr->val);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int A[8] = {1,2,3,4,5,6,7,8};
    int *ptrA = A;
    size_t n = sizeof(A)/sizeof(A[0]);
    nodePtr headPtr = malloc(sizeof(n)); //pointer of type struct
    createList(ptrA,n,headPtr);

    insert(&headPtr,10,4);
    dispCirc(headPtr);
    delete(&headPtr,4);
    dispCirc(headPtr);

    return 0;
}
