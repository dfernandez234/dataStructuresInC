#ifndef sortingT
#include<stdio.h>
#include<stdlib.h>

void swap(int *A, int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void displayArr(int *A, int n){
    for (int i = 0; i < n-1; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void BubbleSort(int *A, int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1-i; j++){
            if(A[j]>A[j+1]){
                swap(A,j,j+1);
            }
        }
    }
    displayArr(A,n);
}

void insertSort(int *A, int n){
    int j;
    int comp;
    for (size_t i = 1; i < n-1; i++){
        j = i-1;
        comp = A[i];
        while (j>-1 && A[j]>comp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = comp;
    }
}

void selectSort(int *A, int n){
    int i,j,k;
    for (i = 0; i < n-1; i++){
        for (j = k = i; j < n-1; j++){
            if(A[j]<A[k]){
                k = j;
            }
        }
        swap(A,i,k);
    }
}

#define sortingT
#endif