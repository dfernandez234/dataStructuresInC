#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//struct containing the linked list
typedef struct Arrays {
  int *Data;
  int size;
  int length;
}Arr;

//define a type for a pointer pointing towards the first elemente
typedef Arr * ArrPtr;

void printArr(ArrPtr *Array){
    ArrPtr firstElement = *Array;
    for (int i = 0; i < firstElement->length; i++){
        printf("%d",firstElement->Data[i]);
    }
    printf("\n");
    printf("%d\n",firstElement->length);
    printf("\n");
}

void Append(ArrPtr *Array, int value){
    ArrPtr firstElement = *Array;
    firstElement->Data[firstElement->length++] = value;
    firstElement = *Array;
}

void Insert(ArrPtr *Array, int value, int position){
    ArrPtr firstElement = *Array;
    if(position>=0 && position <=firstElement->length){
        for (int i = firstElement->length; i > position; i--){
            firstElement->Data[i] = firstElement->Data[i-1];
        }
        firstElement->Data[position] = value;
        firstElement->length+=1;
        firstElement = *Array;
    }
}

void deletion(ArrPtr *Array, int position){
    for (int i = position; i < (*Array)->length-1; i++){
        (*Array)->Data[i] = (*Array)->Data[i+1];        
    }
    (*Array)->length-=1;
}

int binSearch(ArrPtr *Array, int key){
    int low, mid, high;
    high = ((*Array)->length)-1;
    low = 0;
    while (low<=high){
        mid = floor((low+high)/2);
        if ((*Array)->Data[mid] > key){
            low = mid+1;
        }
        if ((*Array)->Data[mid] < key){
            high = mid-1;
        }
        if ((*Array)->Data[mid] == key){
            printf("Element %d found at position %d\n",key,mid);
            return mid;
        }
    }
    return 0;
}

void reverseArr(ArrPtr *Array){
    int tmp = 0;
    for (int i = 0, j = (*Array)->length-1; i<j;i++ ,j--){
        tmp = (*Array)->Data[i];
        (*Array)->Data[i] = (*Array)->Data[j];
        (*Array)->Data[j] = tmp;
    }
}

void rightShift(ArrPtr *Array){
    for (int i = 0; i<(*Array)->length-1;i++){
        (*Array)->Data[i] = (*Array)->Data[i+1];
    }
}


int main(int argc, char const *argv[])
{
    ArrPtr arr1;
    arr1 = malloc(sizeof(ArrPtr));
    arr1 ->length = 5;
    arr1 ->size = 10;

    arr1->Data = (int*)malloc(10*sizeof(int));

    for (int i = 0; i < arr1->length; i++){
        arr1->Data[i] = i+1;
    }
    
    printArr(&arr1);
    Insert(&arr1,8,2);
    printArr(&arr1);
    Append(&arr1, 9);
    printArr(&arr1);
    deletion(&arr1, 4);
    printArr(&arr1);
    rightShift(&arr1);
    printArr(&arr1);


    return 0;
}
