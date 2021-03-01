#include<stdio.h>
#include<stdlib.h>


void perm(char S[], int k){
     static int A[10]={0};
     static char Res[10];
     int i;
     if(S[k]=='\0'){
         Res[k]='\0';
         printf("%s\n",Res);
     }else{
         for (i = 0;S[i]!='\0';i++){
             if(A[i]==0){
                 Res[k]=S[i];
                 A[i]=1;
                 perm(S,k+1);
                 A[i]=0; //set the current i back to 0 after next iteration returns
             }
         }
     }
}


int main(int argc, char const *argv[])
{
    char s[]="ABC";
    perm(s,0);
    return 0;
}
