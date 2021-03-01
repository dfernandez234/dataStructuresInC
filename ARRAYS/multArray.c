//mutidimensional array using double pointer
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int **A;
    A = (int**)malloc(3*sizeof(int));
    A[0] = (int*)malloc(4*sizeof(int));
    A[1] = (int*)malloc(4*sizeof(int));
    A[2] = (int*)malloc(4*sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        printf("Address of element %d inside A %p\n",i,A+i);
        for (int j = 0; j < 3; j++)
        {
            printf("Address of element [%d][%d] on A %p\n",i,j,(*(A+i))+j);
        }
        
    }
    
    return 0;
}
