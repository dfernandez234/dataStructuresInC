#include<stdio.h>
#include<stdlib.h>
#include "BSTMethods.h"

int main(int argc, char const *argv[])
{
    TNodePtr root = (TN*)malloc(sizeof(TN));
    root = NULL;
    insertion(&root,10);
    insertion(&root,5);
    insertion(&root,20);
    insertion(&root,8);
    insertion(&root,30);
    //in_order(&root);
    iInorder(&root);
    deleteVal(&root,20);
    iInorder(&root);
    return 0;
}
