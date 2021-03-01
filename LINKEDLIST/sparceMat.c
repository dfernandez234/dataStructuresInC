#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int col;
    int data; 
    struct Node *next;
}n;

typedef n* nodePtr;



void CreateStruct(nodePtr A[], size_t nonZero ,int *rows ,int* cols, int *vals){
    int curr = *rows;
    nodePtr prev;
    //hash occurrences by row
    int *hashArr = (int*)malloc(5*sizeof(int));
    for (int i = 0; i < nonZero; i++){
        hashArr[*rows++]++;
    }
    for (int i = 0; i < 6; i++){
        prev = A[i];
        for(int j=0;j<hashArr[i];j++){
            nodePtr newNode = (n*)malloc(sizeof(n));
            newNode->data = *(vals++);
            newNode->col = *(cols++);
            newNode->next = NULL;
            prev->next = newNode;
            prev = newNode;
        }
    }
    free(hashArr);
}

void display(nodePtr A[]){
    nodePtr prev;
    for (int i = 1; i < 6; i++){
        prev = A[i];
        for(int j = 0; j < 6; j++){
            if(j==prev->col && prev!=NULL){
                prev = prev->next;
                printf("%d",prev->data);
            }else{
                printf("0");
            }
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    //Array of head pointers
    nodePtr A[5];
    //allocate head pointers
    for (int i = 0; i < 6; i++){
        A[i] = malloc(sizeof(n));
    }
    //print head pointer address
    for (int i = 0; i < 6; i++){
        printf("%p\n",A[i]);
    }

    //nodePtr (*ptrA) = &A;

    int row[7] = {1,2,3,3,4,5,5};
    int col[7] = {4,3,1,4,5,1,4};
    int x[7] = {8,7,5,9,3,6,4};
    size_t n = sizeof(row)/sizeof(row[0]);

    int *rowPtr = row;
    int *colPtr = col;
    int *ptrX = x;

    printf("\n");
    CreateStruct(A,n,rowPtr,colPtr,ptrX); 
    display(A);
    return 0;
}
