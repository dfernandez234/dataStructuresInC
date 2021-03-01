//contains definition of binary tree struct
#ifndef binTree
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

#define binTree
#endif