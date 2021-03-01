//static variables with recursion

#include <stdio.h>

int add(int n){
    if (n>0){
        return add(n-1)*n;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    printf("%d",add(7));
    return 0;
}
