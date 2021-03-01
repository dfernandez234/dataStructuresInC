#include<stdio.h>
#include<stdlib.h>

const int m = 4;
const int n = 4;

void printDiagonal(int A[m][n]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(i==j){
                printf("%d",A[i][j]);
            }else{
                printf("0");
            }
        }
        printf("\n");   
    }
}


void printUpTriag(int A[m][n]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(i>=j){
                printf("%d",A[i][j]);
            }else{
                printf("0");
            }
        }
        printf("\n");   
    }
}


void printLowTriag(int A[m][n]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(i<=j){
                printf("%d",A[i][j]);
            }else{
                printf("0");
            }
        }
        printf("\n");   
    }
}


void isSymmetric(int A[m][n]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(A[i][j] == A[j][i]){
                printf("It is symmetric\n");
            }
        }   
    }
}

int main(int argc, char const *argv[])
{
    int A[4][4] ={{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    int A2[4][4] ={{2,2,2,2},{2,3,3,3},{2,3,4,4},{2,3,4,5}};
    printDiagonal(A);
    printf("\n");   
    printUpTriag(A);
    printf("\n");   
    printLowTriag(A);
    printf("\n");
    isSymmetric(A);
    return 0;
}
