#include<stdio.h>
#include<stdlib.h>
//struct defining each node
typedef struct TNode{
    struct TNode *lchild;
    struct TNode *rchild;
    int data;
}TN;
//Pointer toweards Tree Node
typedef TN* TNodePtr;


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

int isEmptyS(SNodePtr Stack){
    if(Stack->Top == NULL){
        return 1;
    }else{
        return 0;
    }
}

//search element
TNodePtr search(TNodePtr *Root, int key){
    TNodePtr current = *Root;
    while (current!=NULL){
        if(key == current->data){
            return current;
        }
        else if(key<(*Root)->data){
            current = current->lchild;
        }else{
            current = current->rchild;
        }
    }
    return NULL;
}

void insertion(TNodePtr *Root, int val){
    TNodePtr current = *Root;
    TNodePtr tail = NULL;
    if(search(Root, val)!=NULL){
        return;
    }
    if(*Root==NULL){
        TNodePtr newNode = (TN*)malloc(sizeof(TN));
        newNode->data = val;
        newNode->lchild = newNode->rchild = NULL;
        *Root = newNode;
        return;
    }
    while (current!=NULL){
        tail = current;
        if(val<current->data){
            current = current->lchild;
        }else{
            current = current->rchild;
        }
    }
    TNodePtr newNode = (TN*)malloc(sizeof(TN));
    newNode->data = val;
    newNode->lchild = newNode->rchild = NULL;
    if (val<tail->data){
        tail->lchild = newNode;
    }else{
        tail->rchild = newNode;
    }
}

//iterative in order
void iInorder(TNodePtr Root){
    SNodePtr inOrdStack = (SN*)malloc(sizeof(SN));
    TNodePtr curr = Root;
    if(Root == NULL){
        return;
    }
    while (curr!=NULL || !isEmptyS(inOrdStack)){
        if (curr!=NULL){
            push(&inOrdStack,curr);
            curr = curr->lchild;
        }else{
            curr = pop(&inOrdStack);
            printf("%d",curr->data);
            curr = curr->rchild;
        }
    }
    printf("\n");
}

//delete recursively
TNodePtr deleteVal(TNodePtr *Root, int key){
    TNodePtr curr = *Root;
    TNodePtr prev = NULL;
    //tree is empty
    if(*Root == NULL){
        return NULL;
    }
    //search for node inside tree
    while (curr!=NULL && curr->data != key){
        prev = curr;
        if(key<curr->data){
            *Root = (*Root)->lchild;
        }
        else if(key>curr->data){
            *Root = (*Root)->rchild;
        }
    }

    if(curr==NULL){
        printf("Key provided not found on BST\n");
        return NULL;
    }
    //check if key given is a leaf node
    free(*Root);
    return *Root;
}

int main(int argc, char const *argv[])
{
    TNodePtr root = (TN*)malloc(sizeof(TN));
    insertion(&root,10);;
    insertion(&root,5);
    insertion(&root,20);
    insertion(&root,8);
    insertion(&root,30);
    iInorder(root);
    //deleteVal(&root,30);
    iInorder(root);
    free(root);
    return 0;
}