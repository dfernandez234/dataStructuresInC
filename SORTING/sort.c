#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "sortingT.h"

void insert(int *A,int val, int n){
    int i = n-1;
    while (A[i]>val && i>=0){
        A[i] = A[i-1];
        i--; 
    }
    A[i] = val; 
}

int main(int argc, char const *argv[])
{
    time_t t;
    srand((unsigned) time(&t));
    int *A = (int*)malloc(100*sizeof(int));
    int n = rand() % 50;
    for (int i = 0; i < n; i++){
        A[i] = rand() % 100;
    }
    
    displayArr(A,n);
    selectSort(A,n);
    displayArr(A,n);
    
    return 0;
}
