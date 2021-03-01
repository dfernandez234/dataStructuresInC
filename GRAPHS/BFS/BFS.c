//BFS using adjacency matrix and adjacency list
#include<stdio.h>
#include<stdlib.h>
#include "Q.h"

void BFS(int vtx, int A[][8], int n){ //define BFS initial value, matrix, n of vertices
    int xplr;
    qNPtr explr = (qn*)malloc(sizeof(qn));
    int *visited = (int*)malloc(n*sizeof(int));
    printf("%d ",vtx);
    visited[vtx] = 1;
    enqueue(&explr,vtx);
    while (!isEmptyQ(explr)){
        xplr = dequeue(&explr);
        for (int j = 1; j < n; j++){
            if(A[xplr][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j] = 1;
                enqueue(&explr,j);
            }
        } 
    }
}


int main(int argc, char const *argv[])
{
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0}};
    
    BFS(5,A,8);
    return 0;
}
