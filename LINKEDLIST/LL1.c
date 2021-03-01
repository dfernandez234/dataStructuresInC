#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

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
}

int count(nodePtr head){
    int count = 0;
    while (head){
        head = head->next;
        count++;
    }
    return count;
}

int sum(nodePtr head){
    int sum=0;
    while (head){
        sum+=head->val;
        head = head->next; 
    }
    return sum;
}

//insert
void insert(nodePtr *headptr,int pos,int value){
    nodePtr new_node = (n*)malloc(sizeof(n)); //memory allocation for the new element
    nodePtr CurrentPos = *headptr;
    new_node->val = value;
    if(pos == 0){
        new_node->next = *headptr;
        *headptr = new_node;
    }else{ 
        for(int i = 0; i<pos-1; i++){ //traverse list until we set on the position we want
            CurrentPos = CurrentPos->next; 
        }
        new_node ->next = CurrentPos->next; //shift the list after the new node
        CurrentPos->next = new_node;
    }
}

void delete(nodePtr *headptr,int pos){
    nodePtr prev, currentPos = *headptr;
    if (pos == 0){
        prev = *headptr;
        *headptr = (*headptr)->next;
        free(prev);
    }else{
        for(int i = 0; i<pos-1; i++){ //traverse list until we set on the position we want
            prev = currentPos;
            currentPos = currentPos->next; 
        }
        prev->next = currentPos->next;
        free(currentPos);
    }
}


void deleteDups(nodePtr *headptr){
    nodePtr prev = *headptr, currentPos = (*headptr)->next;
    while (currentPos!=NULL){
        if (prev->val != currentPos->val){
            prev = currentPos;
            currentPos = currentPos->next;
        }else{
            prev->next = currentPos->next;
            free(currentPos);
            currentPos = prev->next;
        }
    }
}

void reverse(nodePtr *headptr){
    nodePtr current = *headptr;
    nodePtr prev=NULL, next=NULL;
    while (current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headptr = prev;
}

void append(nodePtr l1, nodePtr l2){
    while (l1->next!=NULL){
        l1 = l1->next;
    }
    l1->next = l2;
    l2 = NULL;
}

void displayList(nodePtr head){
    while (head!=NULL){
        printf("%d->",head->val);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int A[8] = {1,2,3,4,5,6,7,8};
    int B[5] = {1,2,3,4,5};
    int *ptrA = A;
    int *ptrB = B;
    size_t n = sizeof(A)/sizeof(A[0]);
    size_t nb = sizeof(B)/sizeof(B[0]);
    nodePtr headPtr = malloc(sizeof(n)); //pointer of type struct
    nodePtr headPtr2 = malloc(sizeof(n));

    createList(ptrA,n,headPtr);
    createList(ptrB,nb,headPtr2);

    insert(&headPtr,5,5);
    insert(&headPtr,7,7);
    reverse(&headPtr);
    displayList(headPtr);
    displayList(headPtr2);

    append(headPtr, headPtr2);
    displayList(headPtr);
    return 0;
}
