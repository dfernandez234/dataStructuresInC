#include<stdio.h>
#include<stdlib.h>

int len(int *Array){
    int count = 0;
    while (Array[count+1]!=0){
        count++;
    }
    return count;
}

int Max(int *Array){
    int ln= len(Array);
    int max = Array[0];
    for (int i = 0; i < ln; i++){
        if(Array[i]>max){
            max = Array[i];
        }
    }
    return max;
}

void printArr(int *Array){
    int ln= len(Array);
    for (int i = 0; i < ln; i++){
        printf("%d",Array[i]);
    }
    printf("\n");
}


void hashMissing(int *Array){
    int ln = len(Array);
    int max = Max(Array);
    int *hashArr = (int*)malloc(max*sizeof(int));
    for (int i = 0; i < ln; i++){
        hashArr[Array[i]]++;
    }
    for (int i = 0; i <= max; i++){
        if(hashArr[i]==0){
            printf("Element %d missing\n",i);
        }
    }
    free(hashArr);
}

void hashDuplicates(int *Array){
    int ln = len(Array);
    int max = Max(Array);
    int *hashArr = (int*)malloc(max*sizeof(int));
    for (int i = 0; i < ln; i++){
        hashArr[Array[i]]++;
    }
    for (int i = 0; i <= max; i++){
        if(hashArr[i]>1){
            printf("Element %d is duplicated\n",i);
        }
    }
    free(hashArr);
}

void hashSum(int *Array, int target){
    int ln = len(Array);
    int max = Max(Array);
    int *hashArr = (int*)malloc(max*sizeof(int));
    int t=0;
    for (int i = 0; i < ln-1; i++){
        t = target - Array[i];
        hashArr[Array[i]]++;
        if (hashArr[t]!=0){
            printf("%d+%d=%d\n",Array[i],t,target);
        }
    }
}

int main(int argc, char const *argv[])
{
    int *array = (int*)malloc(6*sizeof(int));
    int count=0;
    for (int i = 0; i < 12; i++){
        if(i%2==0){
            array[count] = i;
            count++;
        }
    }
    int arr2[10]={8,3,6,4,6,5,6,8,2,7};
    int* array2 = (int*)malloc(10*sizeof(int));
    array2 = arr2;

    hashSum(array2,10);

    return 0;
}
