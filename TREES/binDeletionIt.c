#include<stdio.h>
#include<stdlib.h>
#include"stackMethods.h"
#include"binTree.h"

void insertion(TNodePtr *root, int key){
    TNodePtr curr = *root;
    TNodePtr tail = NULL;
    if(*root == NULL){
        TNodePtr newNode = (TN*)malloc(sizeof(TN));
        newNode->data = key;
        newNode->lchild = newNode->rchild = NULL;
        *root = newNode;
        return;
    }
    while (curr!=NULL){
        tail = curr;
        if(key>curr->data){
            curr = curr->rchild;
        }
        else if(key<curr->data){
            curr = curr->lchild;
        }
        else{
            return;
        }
    }
    TNodePtr newNode = (TN*)malloc(sizeof(TN));
    newNode->data = key;
    newNode->lchild = newNode->rchild = NULL;   
    if(key>tail->data)
        tail->rchild = newNode;
    else
        tail->lchild = newNode;
}

//auxiliary functions to find succesors and predecessor
//find in-order predecesor
TNodePtr inOrdPred(TNodePtr root){
    TNodePtr leftSub = root->lchild;
    while (leftSub->lchild!=NULL){
        leftSub = leftSub->lchild;
    }
    return leftSub;
}
//fond in-order sucessor
TNodePtr inOrdSuc(TNodePtr root){
    TNodePtr rightSub = root->rchild;
    while (rightSub->rchild!=NULL){
        rightSub = rightSub->rchild;
    }
    return rightSub;
}

int height(TNodePtr root){
    int x,y;
    if(root){
        x = height(root->lchild);
        y = height(root->rchild);
        if(x>y){
            return x+1;
        }else{
            return y+1;
        }
    }
    return 0;
}

TNodePtr deletion(TNodePtr *root, int key){
    //if tree is empty
    if(*root == NULL){
        return NULL;
    }
    //find node inside tree
    TNodePtr curr = *root;
    while (curr!=NULL&&curr->data!=key){
        if(key>curr->data){
            curr = curr->rchild;
        }
        else if(key<curr->data){
            curr = curr->lchild;
        }
    }
    if (curr == NULL){
        printf("Key was not found\n");
        return *root;
    }
    
    //check if node is a leaf node 
    if(curr->lchild==NULL && curr->rchild==NULL){
        free(curr);
        return NULL;
    }
}

void inOrd(TNodePtr *root){
    SNodePtr addStack = (SN*)malloc(sizeof(SN));
    if(*root==NULL){
        return;
    }
    TNodePtr curr = *root;
    while (curr!=NULL || !isEmptyS(addStack)){
        if(curr!=NULL){
            push(&addStack,curr);
            curr = curr->lchild;
        }else{
            curr = pop(&addStack);
            printf("%p\n ",curr);
            curr = curr->rchild;
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[]){
    TNodePtr Root = (TN*)malloc(sizeof(TN));
    Root = NULL;
    insertion(&Root, 10);
    insertion(&Root, 5);
    insertion(&Root, 20);
    insertion(&Root, 8);
    insertion(&Root, 30);
    inOrd(&Root);
    free(Root);
    inOrd(&Root);
    return 0;
}
