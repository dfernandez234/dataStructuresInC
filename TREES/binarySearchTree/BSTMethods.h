//library defining operations performed on binary search trees
#ifndef BSTMethods
#include<stdio.h>
#include<stdlib.h>
#include "/media/davidtp/WC-Drive/Courses/DATASTRUCTURES/TREES/stackMethods.h"
#include "/media/davidtp/WC-Drive/Courses/DATASTRUCTURES/TREES/binTree.h"

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

//search for element recursively
TNodePtr rsearch(TNodePtr *Root, int key){
    TNodePtr current = *Root;
    if(current == NULL){
        return NULL;
    }
    if (key == current->data){
        return current;
    }
    else if(key < current->data){
        rsearch(&(current->lchild), key);
    }else{
        rsearch(&(current->rchild), key);
    }
}

//insertion method
void insertion(TNodePtr *Root, int val){
    TNodePtr current = *Root;
    TNodePtr tail = NULL;
    if(*Root==NULL){
        TNodePtr newNode = (TN*)malloc(sizeof(TN));
        newNode->data = val;
        newNode->lchild = newNode->rchild = NULL;
        *Root = newNode;
        return;
    }
    while (current!=NULL){
        tail = current;
        if(val == current->data){
            return;
        }
        else if(val<current->data){
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


//traversal methods
//inorder
void in_order(TNodePtr *Root){
    if(*Root){
        in_order(&((*Root)->lchild));
        printf("%d\n", (*Root)->data);
        in_order(&((*Root)->rchild));
    }
}

//iterative in order
void iInorder(TNodePtr *Root){
    SNodePtr inOrdStack = (SN*)malloc(sizeof(SN));
    TNodePtr curr = *Root;
    if(*Root == NULL){
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

//find height of a given subtree
int height(TNodePtr *Root){
    int x,y;
    if(*Root){
        x = height(&((*Root)->lchild));
        y = height(&((*Root)->rchild));
        if(x>y){
            return x+1;
        }else{
            return y+1;
        }
    }
    return 0;
}

//deletion methods
//find in-order predecesor
TNodePtr inOrdPred(TNodePtr *Root){
    TNodePtr leftSub = (*Root)->lchild;
    while (leftSub->lchild!=NULL){
        leftSub = leftSub->lchild;
    }
    return leftSub;
}
//fond in-order sucessor
TNodePtr inOrdSuc(TNodePtr *Root){
    TNodePtr rightSub = (*Root)->rchild;
    while (rightSub->rchild!=NULL){
        rightSub = rightSub->rchild;
    }
    return rightSub;
}

//delete recursively
TNodePtr deleteVal(TNodePtr *Root, int key){
    TNodePtr curr = *Root;
    TNodePtr prev = NULL;
    TNodePtr del = (TN*)malloc(sizeof(TN));
    //tree is empty
    if(*Root == NULL){
        return NULL;
    }
    //search for node inside tree
    while (curr!=NULL && curr->data != key){
        prev = curr;
        if(key<curr->data){
            curr = curr->lchild;
        }
        else if(key>curr->data){
            curr = curr->rchild;
        }
    }

    if(curr==NULL){
        printf("Key provided not found on BST\n");
        return NULL;
    }
    //check if key has one child
    if(curr->lchild!=NULL || curr->rchild!=NULL){
        //check which child is not null
        TNodePtr newCurr; 
        if (curr->lchild == NULL) 
            newCurr = curr->rchild; 
        else
            newCurr = curr->lchild; 
        if(prev == NULL){
            return newCurr;
        }
        //assign new succession
        if (curr == prev->lchild) 
            prev->lchild = newCurr; 
        else
            prev->rchild = newCurr; 
        free(curr);
    }
    else{
        //deal with nodes with two children, based on the height of subtrees
        //pick either in-ord predecessor or successor to replace
        TNodePtr p = NULL;
        TNodePtr temp;
        // Compute the inorder successor 
        temp = curr->rchild; 
        while (temp->lchild != NULL) { 
            p = temp; 
            temp = temp->lchild; 
        }
        if (p != NULL) 
            p->lchild = temp->rchild; 
        else
            curr->rchild = temp->rchild;  
        
        curr->data = temp->data; 
        free(temp); 
    }
    return *Root;
}

#define BSTMethods
#endif