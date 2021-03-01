#include <stdio.h>
#include <stdlib.h>

//struct containing the linked list
typedef struct node {
  int data;
  struct node *next;
}node_t;

//define a type for a pointer pointing towards the first elemente
typedef node_t * ListNodePtr;
struct node_t *head = NULL, *ptr;

//insert a node at the beginning of the list
void inserNodeFirst (ListNodePtr *headptr, int value){ 
    ListNodePtr new_node = malloc(sizeof(node_t)); //memory allocation for the new element
    new_node -> data = value; //asign value to our new element
    new_node -> next = *headptr; //dereference double pointer,and assign old head value to the a next node
    *headptr = new_node; //define new node as the new head
}

void insertNodeLast(ListNodePtr *headptr, int value){
    //allocate memory
    ListNodePtr new_node = malloc(sizeof(node_t)); //memory allocation for the new element
    //check if the list is empty insert at beginning
    if(*headptr == NULL){
        inserNodeFirst(headptr, value);
    }else{ 
        ListNodePtr CurrentPos = *headptr;
        //walk to the last element
        while (CurrentPos->next != NULL){
            CurrentPos = CurrentPos-> next; // move until the last list element
        }
        CurrentPos ->next = new_node; //insert element as the next following last element found
        new_node -> next = NULL; //set as the last element
        new_node -> data = value;
    }
}

void insertNodeAtPosition(ListNodePtr *headptr, int value, int pos){
      //allocate memory
    ListNodePtr new_node = malloc(sizeof(node_t)); //memory allocation for the new element
    ListNodePtr CurrentPos = *headptr;
    ListNodePtr Prev;
    if(*headptr == NULL || pos == 1){
        inserNodeFirst(headptr, value);
    }else{ 
        int count = 0;
        while(count != pos){ //traverse list until we set on the position we want
            Prev = CurrentPos; //save the previous node of our position
            CurrentPos = CurrentPos->next; 
            count++;
        }
        Prev -> next = new_node; //set the next value of our previous node to our new node
        new_node ->next = CurrentPos; //shift the list after the new node
        new_node ->data = value;
    }
}

void deleteNodeAnyPosition(ListNodePtr *headptr, int pos){
    ListNodePtr CurrentPos = *headptr;
    ListNodePtr temp, Prev;
    if(pos==1){
        temp = CurrentPos -> next;
        free(*headptr);
        *headptr = temp;
    }else{
        int count = 0;
        while(count != pos){ //traverse list until we set on the position we want
            Prev = CurrentPos; //save the previous node of our position
            CurrentPos = CurrentPos->next; 
            count++;
        }
        temp = CurrentPos ->next;
        free(Prev->next);
        Prev ->next = temp;
    }
}


void updateNodeValue(ListNodePtr *headptr, int pos, int newVal){
    ListNodePtr CurrentPos = *headptr;
    if(pos==1){
        CurrentPos -> data = newVal;
    }else{
        int count = 0;
        while(count != pos){ //traverse list until we set on the position we want
            CurrentPos = CurrentPos->next; 
            count++;
        }
        CurrentPos ->data = newVal;
    }
}

void searchElement(ListNodePtr *headptr, int val){
    ListNodePtr CurrentPos = *headptr;
    int pos = 0;
    while (CurrentPos->next != NULL){
        if(CurrentPos -> data == val){
            printf("Value %d was found at position %d\n",val,pos);
        }
        CurrentPos = CurrentPos-> next; // move until the last list element
        pos++;
    }
    printf("\n");
}

int length(ListNodePtr *headptr){
    ListNodePtr CurrentPos = *headptr;
    int counter=1;
    while (CurrentPos->next != NULL){
        ++counter;
        CurrentPos = CurrentPos->next;
    }
    return counter;
}

void reverseList(ListNodePtr *headptr){
    ListNodePtr CurrentPos = *headptr;
    ListNodePtr next, Prev = NULL;
    printf("%d",CurrentPos->data);
    while (CurrentPos->next != NULL){
        next = CurrentPos->next; 
        // Reverse current node's pointer 
        CurrentPos->next =  Prev; 
        // Move pointers one position ahead. 
        Prev = CurrentPos; 
        CurrentPos = next; 
    }
    *headptr = Prev;

}

void printList(ListNodePtr currentPtr){
    if (currentPtr == NULL){
        printf("List is empty");
    }else{
        while (currentPtr != NULL){
            printf("%d-->",currentPtr->data);
            currentPtr = currentPtr->next;
        }
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    ListNodePtr head = NULL; //pointer for the list head
    int item = 0;
    inserNodeFirst(&head, 6);
    inserNodeFirst(&head, 7);
    inserNodeFirst(&head, 8);
    inserNodeFirst(&head, 7);
    insertNodeLast(&head, 15);
    //printList(head);


    insertNodeAtPosition(&head, 10, 3);
    //printList(head);
    //deleteNodeAnyPosition(&head, 3);
    //printList(head);
    //updateNodeValue(&head, 2, 18);
    //printList(head);
    //inserNodeFirst(&head, 6);
    printList(head);
    //searchElement(&head, 6);
    reverseList(&head);
    printList(head);
    return 0;
}
