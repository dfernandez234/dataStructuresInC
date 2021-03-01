#include<stdio.h>
#include<stdlib.h>
#include "queueMethods.h"
#include "stackMethods.h"

TNodePtr root;

void createTree(){
    int value;
    QNodePtr q1 = (QN*)malloc(sizeof(QN));
    char scape;
    int count = 0;

    //temp pointers
    TNodePtr curr, temp;

    printf("Enter Root: ");
    scanf("%d", &value);
    root = (TN*)malloc(sizeof(TN));
    root->data = value;
    root->lchild = NULL;
    root->rchild = NULL;

    //enQ root
    enqueue(&q1,root);

    while (!isEmptyQ(q1)){
        curr = dequeue(&q1);
        printf("Enter left child of %d: ", curr->data);
        scanf("%d", &value);
        if(value!=-1){
            temp = (TN*)malloc(sizeof(TN));
            temp->lchild = NULL;
            temp->rchild = NULL;
            temp->data = value;
            curr->lchild = temp;
            enqueue(&q1,temp);
        }
        printf("Enter right child %d: ", curr->data);
        scanf("%d", &value);
        if(value!=-1){
            temp = (TN*)malloc(sizeof(TN));
            temp->lchild = NULL;
            temp->rchild = NULL;
            temp->data = value;
            curr->rchild = temp;
            enqueue(&q1,temp);
        }
    }
}

//recursive traversal methods
void Preorder(TNodePtr T){
    if(T){
        printf("%d", T->data);
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}

void in_order(TNodePtr T){
    if(T){
        in_order(T->lchild);
        printf("%d", T->data);
        in_order(T->rchild);
    }
}

void postorder(TNodePtr T){
    if(T){
        in_order(T->lchild);
        in_order(T->rchild);
        printf("%d", T->data);
    }
}

//iterative traversal methods
void iPreorder(TNodePtr *Root){
    int flag = 0;
    SNodePtr Stack1 = (SN*)malloc(sizeof(SN));
    TNodePtr Curr = *Root;
    push(&Stack1,Curr);
    while (Curr!=NULL || !isEmptyS(Stack1)){
        if(flag==0){
            pop(&Stack1);
            flag=-1;}
        if (Curr!=NULL){
            printf("%d", Curr->data);
            push(&Stack1,Curr);
            Curr = Curr->lchild;
        }else{
            Curr = pop(&Stack1);
            Curr = Curr->rchild;
        }
    }   
}

void iInOrder(TNodePtr *Root){
    SNodePtr Stack2 = (SN*)malloc(sizeof(SN));
    TNodePtr Curr = *Root;
    push(&Stack2,Curr);
    int flag = 0;
    while (Curr!=NULL || !isEmptyS(Stack2)){
        if(flag==0){
            pop(&Stack2);
        flag=-1;}
        if (Curr!=NULL){
            push(&Stack2,Curr);
            Curr = Curr->lchild;
        }else{
            Curr = pop(&Stack2);
            printf("%d", Curr->data);
            Curr = Curr->rchild;
        }

    }
}

void iLevelT(TNodePtr *Root){
    QNodePtr levelQ = (QN*)malloc(sizeof(QN));
    enqueue(&levelQ,*Root);
    TNodePtr curr;
    while(!isEmptyQ(levelQ)){
        curr = dequeue(&levelQ);
        if(curr->lchild != NULL){
            enqueue(&levelQ, curr->lchild);
        }
        if(curr->rchild != NULL){
            enqueue(&levelQ, curr->rchild);
        }
        printf("%d --",curr->data);
    }
    
}

int fun(TNodePtr T){
    int x,y;
    if(T){
        x = fun(T->lchild);
        y = fun(T->rchild);
        if(x>y){
            return x+1;
        }else{
            return y+1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{   
    createTree();
    printf("Root: %d\n", root->data);
    Preorder(root);
    printf("\n");
    in_order(root);
    printf("\n");
    postorder(root);
    printf("\n");
    iPreorder(&root);
    printf("\n");
    iInOrder(&root);
    printf("\n");
    iLevelT(&root);
    printf("\n");

    printf("%d\n",fun(root));
    return 0;
}
