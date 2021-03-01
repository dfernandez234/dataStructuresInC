#include<stdio.h>
#include<stdlib.h>

typedef struct Element{
    int i;
    int j;
    int x;
}Element;

typedef struct sparse{
    int m;
    int n;
    int num;
    Element *e;
}sparse;

void PrintM(sparse *s){
    int k = 0;
    for (int i = 1; i <=s->m; i++){
        for (int j = 1; j <= s->n; j++){
            if(s->e[k].i==i && s->e[k].j==j){
                printf("%d\t",s->e[k].x);
                k++;
            }else{
                printf("0\t");
            }
        }
        printf("\n");
    }
}

void Create(sparse *s, int m, int n, int nonZ ,int *Elements, int *ci, int *cj){
    s->m = m;
    s->n = n;
    s->num = nonZ;
    //allocate memory for a total number of elements represented each one by a struct element
    s->e = malloc((s->num)*sizeof(Element));    

    for (int i = 0; i < s->num; i++){
        s->e[i].i = *ci;
        s->e[i].j = *cj;
        s->e[i].x = *Elements;

        ci++;
        cj++;
        Elements++;
    }
}

void addition(sparse *s1, sparse *s2){
    sparse *result = (sparse*) malloc(sizeof(sparse));
    result->e = malloc((s1->num+s2->num)*sizeof(Element)); 
    int i=0,j=0,k=0;
    result->m=s1->m;
    result->n=s1->n;
    while (i<s1->num && j<s2->num){
        if (s1->e[i].i == s2->e[j].i && s1->e[i].j == s2->e[j].j){
            result->e[k].x = s1->e[i].x + s2->e[j].x;
            result->e[k].i = s1->e[i].i;
            result->e[k].j = s1->e[i].j;
            k++, i++, j++;
        }
        if (s1->e[i].i < s2->e[j].i){
            result->e[k] = s1->e[i];
            i++, k++;
        }
        else if(s1->e[i].i > s2->e[j].i){
            result->e[k] = s2->e[j];
            j++, k++;
        }else{
            if (s1->e[i].j < s2->e[j].j){
            result->e[k] = s1->e[i];
            i++, k++;
            }
            else if(s1->e[i].j > s2->e[j].j){
                result->e[k] = s2->e[j];
                j++, k++;        
            }
        } 
    }
    for(;i<s1->num;i++)result->e[k++]=s1->e[i];
    for(;j<s2->num;j++)result->e[k++]=s2->e[j];
    result->num=k;
    PrintM(result);
}

int main(int argc, char const *argv[])
{
    int ci[5] = {1,2,2,3,4};
    int cj[5] = {3,1,4,1,5};
    int x[5] = {7,2,5,9,4};

    int *pci = ci;
    int *pcj = cj;
    int *px = x;


    int cib[7] = {1,2,2,3,3,3,4};
    int cjb[7] = {5,2,5,1,3,4,4};
    int xb[7] = {8,3,5,2,7,9,9};

    int *pcib = cib;
    int *pcjb = cjb;
    int *pxb = xb;

    sparse spMat1;
    sparse spMat2;

    Create(&spMat1,4,5,5,x,ci,cj);
    PrintM(&spMat1);
    printf("\n");
    Create(&spMat2,4,5,6,xb,cib,cjb);
    PrintM(&spMat2);
    printf("\n");

    addition(&spMat1, &spMat2);
    return 0;
}
