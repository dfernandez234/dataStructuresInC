#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "stackH.h"

nodePtr top = NULL;
nodePtr top2 = NULL;

void matchCheck(char *S){
    while (*S!='\0'){
        if(*S==40){
            push(*S, &top);
        }
        if(*S==41 && !isEmpty(top)){
            pop(&top);      
        }
        S++;
    }
    if(isEmpty(top)){
        printf("Expression is balanced\n");
    }else{
        printf("Mismatch\n");
        display(top);
    }
}

void mismatchEnhanced(char *S){
    while (*S!='\0'){
        if (*S==40 || *S==91 || *S==123){   
            push(*S,&top2);
        }
        if (*S-top2->val == 1 || *S-top2->val == 2){
            pop(&top2);
        }
        S++;
    }
    if(isEmpty(top2)){
        printf("Expression is balanced\n");
    }else{
        printf("Mismatch\n");
        display(top2);
    }
}

int main(int argc, char const *argv[])
{
    char *S = (char*)malloc(20*sizeof(char));
    S = "((a+b)+c+(d*2)&(4))";
    matchCheck(S);
    char *S1 = (char*)malloc(50*sizeof(char));
    S1 = "([a+b]+{c}+{d*2}&(4)$^[5])";
    mismatchEnhanced(S1);
    return 0;
}
