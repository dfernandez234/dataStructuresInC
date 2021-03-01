//describe taylor series for exp, cos and sin using recursion
#include<stdio.h>
#include<math.h>

int fact(int n){
    if (n>0){
        return fact(n-1)*n;
    }
    return 0;
}

double eRec(int x, int n){
    static double power=1, factorial=1;
    double result;
    if (n==0){
        return 1;
    }else{
        result = eRec(x,n-1);
        power = power*x;
        factorial = factorial*(n);
        return result + power/factorial;
    }
}


double sinRec(int x, int n){
    static double power=1, factorial=1;
    int p, f;
    double result;
    if (n==0){
        return x;
    }else{
        result = sinRec(x,n-1);
        f = fact(2*n+1);
        power = pow(x,2*n+1);
        p = pow(-1,n);
        return result + p*(power/f);
    }
}

int main(int argc, char const *argv[])
{
    printf("%lf\n",eRec(6,20));
    printf("%lf\n",sinRec(6,5));
    return 0;
}
