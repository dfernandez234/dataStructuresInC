#include<stdio.h>
#include<stdlib.h>

typedef struct TNode{
    struct TNode *lchild;
    struct TNode *rchild;
    int data;
    int height;
}TN;
//Pointer toweards Tree Node
typedef TN* TNodePtr;
TNodePtr Root;

//auxiliary functions
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


TNodePtr rDeletion(TNodePtr root, int key){
    TNodePtr temp = NULL;
    if(root == NULL){
        return NULL;
    }
    //delete leaf node
    if(root->lchild==NULL && root->rchild==NULL){
        if(root == Root){
            Root = NULL;
        }
        free(root);
        return NULL;
    }
    //perform search and replacement
    if(key<root->data){
        root->lchild = rDeletion(root->lchild, key);
    }
    else if(key>root->data){
        root->rchild = rDeletion(root->rchild,key);
    } else{
        //if node found has children find predecessor or successor
        if (height(root->lchild) > height(root->rchild)){
            temp = inOrdPred(root->lchild);
            root->data = temp->data;
            root->lchild = rDeletion(root->lchild, temp->data);
        } else {
            temp = inOrdSuc(root->rchild);
            root->data = temp->data;
            root->rchild = rDeletion(root->rchild, temp->data);
        }
    }
    return root;
}

//recursive insertion method
TNodePtr itInsert(TNodePtr *root, int key){
    TNodePtr temp = NULL;
    //check if it is first insertion from any subtree
    if (*root == NULL){
        temp = (TN*)malloc(sizeof(TN));
        temp->data = key;
        temp->height = 0;
        temp->rchild=temp->lchild = NULL;
        return temp;
    }
    if(key<(*root)->data)
        (*root)->lchild = itInsert(&(*root)->lchild,key);
    else if (key>(*root)->data)
        (*root)->rchild = itInsert(&(*root)->rchild,key);
    return *root;
}

//inorder
void in_order(TNodePtr *Root){
    if(*Root){
        in_order(&((*Root)->lchild));
        printf("%d -> %d \n",(*Root)->data,(*Root)->height);
        in_order(&((*Root)->rchild));
    }
}


int main(int argc, char const *argv[]){
    Root = itInsert(&Root, 50);
    itInsert(&Root,10);
    itInsert(&Root,5);
    itInsert(&Root,20);
    itInsert(&Root,8);
    itInsert(&Root,30);
    in_order(&Root);
    rDeletion(Root,30);
    in_order(&Root);
    return 0;
}
