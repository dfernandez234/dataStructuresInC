#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

typedef struct Node{
    int val;
    struct Node *next;
}n;

typedef n* nodePtr;

nodePtr front = NULL;
nodePtr rear = NULL;

void enqueue(int val){
    nodePtr newNode = (n*)malloc(sizeof(n));
    if(newNode==NULL){
        printf("Queue FULL");
    }else{
        newNode->val=val;
        newNode->next = NULL;
        //check if it is first element
        if (front == NULL){
            front = rear = newNode;        
        }else{
            //link through rear
            rear->next = newNode;
            rear = newNode;
        }
    }
}

int dequeue(){
    nodePtr del;
    int deq = -1;
    if(front==NULL){
        printf("List is empty\n");
        return deq;
    }else{
        del = front;
        front = front->next;
        deq = del->val;
        return deq;
        free(del);
    }
}

void display(){
    nodePtr curr = front;
    while (curr!=NULL){
        printf("%d -- ",curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int elements[10] = {1,5,6,7,8,4,2,5,6,7};
    for (int i = 0; i < 10; i++){
        enqueue(elements[i]);
    }

    display();
    
    for (int i = 0; i < 4; i++){
        sleep(2);
        dequeue();
        enqueue(elements[i]);
        display();
    }
    
    
    return 0;
}




/*
things to check tomorrow
linux commands
diff
patch

linked list address stacks

finish git course
*/