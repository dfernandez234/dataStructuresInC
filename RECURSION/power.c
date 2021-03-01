//power using recursion
#include <stdio.h>

int power(int base, int pow){
    if (pow==0){
        return 1;
    }else{
        return ((base,pow-1))*base;
    }
    
}

int main(int argc, char const *argv[])
{
    printf("%d",power(5,2));
    return 0;
}
