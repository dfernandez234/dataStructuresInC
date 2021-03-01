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
TNodePtr root = NULL;
//calculating tree nodes
int NodeHeight(TNodePtr *Node){
    int hl, hr;
    hl = *Node && (*Node)->lchild ? (*Node)->lchild->height : 0;
    hr = *Node && (*Node)->rchild ? (*Node)->rchild->height : 0;
    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(TNodePtr *Node){
    int hl, hr;
    hl = *Node && (*Node)->lchild ? (*Node)->lchild->height : 0;
    hr = *Node && (*Node)->rchild ? (*Node)->rchild->height : 0;
    return hl-hr;
}
//LLRotation
TNodePtr LLRot(TNodePtr *Node){
    TNodePtr llchild = (*Node)->lchild;
    TNodePtr llrchild = llchild->rchild;
    llchild->rchild = (*Node);
    (*Node)->lchild = llrchild;

    //readjust height
    (*Node)->height = NodeHeight(Node);
    llchild->height = NodeHeight(&llchild);

    if(*Node == root){
        root = llchild;
    }
    return llchild;
}

//LR-Rotation
TNodePtr LRRot(TNodePtr *Node){
    TNodePtr leftNode = (*Node)->lchild;
    TNodePtr rlNode = leftNode->rchild;

    leftNode->rchild = rlNode->lchild;
    (*Node)->lchild = rlNode->rchild;

    rlNode->lchild = leftNode;
    rlNode->rchild = (*Node);

    (*Node)->height = NodeHeight(Node);
    leftNode->height = NodeHeight(&leftNode);
    rlNode->height = NodeHeight(&rlNode);

    if(*Node == root){
        root = rlNode;
    }
    return rlNode;
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
    //update heaight of each node and calculate balance factor
    //in return time
    (*root)->height = NodeHeight(root);
    //check in return time if any node above new insertion has become 
    //imbalanced, in LL, on a factor no larger than 2
    if(BalanceFactor(root)==2 && BalanceFactor(&(*root)->lchild)==1){
        LLRot(root);
    }
    if(BalanceFactor(root)==2 && BalanceFactor(&(*root)->lchild)==-1){
        LRRot(root);
    }

    //implement RR and RL
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

int main(int argc, char const *argv[])
{
    root = itInsert(&root, 50);
    itInsert(&root,10);
    itInsert(&root,5);
    itInsert(&root,20);
    itInsert(&root,8);
    itInsert(&root,30);
    in_order(&root);
    return 0;
}
