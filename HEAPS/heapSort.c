//implementing heap sort
#include<stdio.h>
#include<stdlib.h>

//max heap insertion from in place array
void maxInsert(int H[], int n){
    int i = n;
    int temp = H[i];
    while (i>1 && H[i/2]<temp){
        H[i] = H[i/2];
        i = i/2;
    }
    H[i]=temp;
}

void minInsert(int H[], int n){
    int i = n;
    int temp = H[i];
    while (i!=0 && H[i/2]>temp){
        H[i] = H[i/2];
        i = i/2;
    }
    H[i]=temp;
}

void delete(int H[], int n){
    int val = H[1];
    H[1] = H[n];
    H[n] = val;
    int i = 1, j = 2*i;
    int temp;
    while (j<=n-1){
        if(j<n-1 && H[j+1]>H[j]){
            j=j+1;
        }
        if(H[i]<H[j]){
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j, j = 2*i;
        }
        else{
            break;
        }
    } 
}


int main(int argc, char const *argv[]){
    int H[]={0,14,15,5,20,30,8,40};
    int H2[]={0,14,15,5,20,30,8,40};
    for (int i = 1; i < 8; i++){
        printf("%d ",H[i]);
    }
    for (int i = 2; i < 8; i++){
        maxInsert(H,i);
    }
    printf("\n");
    for (int i = 1; i < 8; i++){
        printf("%d ",H[i]);
    }
    printf("\n");
    for (int i = 7; i > 1; i--){
        delete(H,i);
    }
    for (int i = 1; i < 8; i++){
        printf("%d ",H[i]);
    }
    printf("\n");
    return 0;
}
