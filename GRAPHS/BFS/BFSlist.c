#include<stdio.h>
#include<stdlib.h>
#include "Q.h"
#include "linkedlist.h"
#define SIZE 8
#define INT_MAX 2147483647

void BFS(int vfx, lNodePtr *adjList, int size){
    int curr;
    lNodePtr currVert;
    qNPtr next = (qn*)malloc(sizeof(qn));
    int *visited = (int*)malloc(size*sizeof(int));
    printf("%d -- ",vfx);
    enqueue(&next,vfx);
    visited[vfx] = 1;
    while (!isEmptyQ(next)){
        curr = dequeue(&next);
        currVert = adjList[curr];
        while (currVert->next!=NULL){
            if (visited[currVert->data]!=1){
                printf("%d -- ",currVert->data);
                visited[currVert->data] = 1;
                enqueue(&next,currVert->data);
            }
            currVert = currVert->next;
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
    sortedInsert(&adjList[1],4);
    //vertex 2
    sortedInsert(&adjList[2],3);
    sortedInsert(&adjList[2],1);
    //vertex 3
    sortedInsert(&adjList[3],2);
    sortedInsert(&adjList[3],1);
    sortedInsert(&adjList[3],4);
    sortedInsert(&adjList[3],5);
    //vertex 4
    sortedInsert(&adjList[4],1);
    sortedInsert(&adjList[4],3);
    sortedInsert(&adjList[4],5);
    //vertex 5
    sortedInsert(&adjList[5],4);
    sortedInsert(&adjList[5],3);
    sortedInsert(&adjList[5],6);
    sortedInsert(&adjList[5],7);
    //vertex 6
    sortedInsert(&adjList[6],5);
    //vertex 7
    sortedInsert(&adjList[7],5);

    for (int i = 1; i < 8; i++){
        sortedInsert(&adjList[i],INT_MAX);
    }


    /*for (int i = 0; i < SIZE; i++){
        display(&adjList[i]); 
    }*/
    printf("\n");
    printf("\n");

    BFS(5, adjList, SIZE);

    printf("\n");

    return 0;
}
