#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}n;

typedef n* nodePtr;
nodePtr top = NULL;

void push(int val){
    nodePtr newNode = (n*)malloc(sizeof(n));
    if (newNode==NULL){
        printf("Stack Overflow");
    }else{
        newNode->next = top;
        newNode->val = val;
        top = newNode;
    }
}

int pop(){
    nodePtr pop;
    int popped = -1;
    if(top==NULL){
        printf("Stack Underflow\n");
        return popped;
    }else{
        pop = top;
        popped = pop->val;
        top = top->next;
        return popped;
        free(pop);
    }
}

void display(){
    nodePtr curr = top;
    while (curr!=NULL){
        printf("%c",curr->val);
        curr = curr->next;
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    printf("\n");
    printf("Popped: %d\n",pop());
    printf("Popped: %d\n",pop());
    display();
    return 0;
}

