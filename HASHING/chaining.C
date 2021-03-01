#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "linkedlist.h"
#define SIZE 10

void chainHash(lNodePtr *H, int val){
    int hfunc = val%10;
    sortedInsert(&H[hfunc],val);
}

lNodePtr search(lNodePtr *H, int key){
    int hfunc = key%10;
    lNodePtr ll = H[hfunc];
    if (H[hfunc] == NULL){
        printf("Hash Empty\n");
        return NULL;
    }else{
        while (ll->data!=key && ll!=NULL){
            ll = ll->next;
        }
        if(ll==NULL){
            printf("Key not found\n");
            return NULL;
        }else{
            return ll;
        }
    }
}

int main(int argc, char const *argv[]){
    //Array of head pointers
    lNodePtr H[SIZE];
    //allocate head pointers
    for (int i = 0; i < SIZE; i++){
        H[i] = (ln*)malloc(sizeof(ln));
        H[i] = NULL;
    }

    chainHash(H,26);
    chainHash(H,37);
    chainHash(H,45);
    chainHash(H,58);
    chainHash(H,15);
    chainHash(H,9);

    printf("%d\n",search(H, 94)->data);
    
    return 0;
}

