#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include "linkedlist.h"
#define SIZE 7
#define INT_MAX 2147483647

void DFS(lNodePtr *adjList, int vfx, int size){
    stNPtr prev = (st*)malloc(sizeof(st));
    lNodePtr curr;
    int cur;
    push(&prev,vfx);
    int *visited = (int*)malloc(size*sizeof(int));
    visited[vfx] = 1;
    while (!isEmptyS(prev)){
        cur = pop(&prev);
        curr = adjList[cur];
        printf("%d --",cur);
        while (curr->next!=NULL){
            if(visited[curr->data]!=1){
                push(&prev,curr->data);
                visited[curr->data] = 1;
            }
            curr = curr->next;            
        }
    }
}

int main(int argc, char const *argv[])
{
    ln* adjList[SIZE];
    //allocate head pointers
    for (int i = 0; i < SIZE; i++){
        adjList[i] = (ln*)malloc(sizeof(ln));
        adjList[i] = NULL;
    }

    //create adj list for graph
    // INT_MAX is dummy value cause list traversing stops 1 element before
    //pls help me with that
    //vertex 1
    sortedInsert(&adjList[1],2);
    sortedInsert(&adjList[1],3);
    //vertex 2
    sortedInsert(&adjList[2],1);
    sortedInsert(&adjList[2],4);
    //vertex 3
    sortedInsert(&adjList[3],1);
    sortedInsert(&adjList[3],4);
    //vertex 4
    sortedInsert(&adjList[4],2);
    sortedInsert(&adjList[4],3);
    sortedInsert(&adjList[4],5);
    sortedInsert(&adjList[4],6);
    //vertex 5
    sortedInsert(&adjList[5],4);
    //vertex 6
    sortedInsert(&adjList[6],4);

    for (int i = 1; i < SIZE; i++){
        sortedInsert(&adjList[i],INT_MAX);
    }

    printf("\n");
    DFS(adjList,4,6);
    printf("\n");
    
    return 0;
}
