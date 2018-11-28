#include <stdio.h>
#include <math.h>

int cauchy(unsigned int k)
{
    int a0 = 0;
    int a1 = 0;
    int a2 = 1;
    int n = 0;
    double bn;

    do{
        n++;
        a0 = a1;
        a1 = a2;
        a2 = a1+ a0;
        bn = (double)a2/a1 - (double) a1/a0;
    }while(fabs(bn) > (double)1/k);
    return n;
}

int main() {
    unsigned int k;
    printf("k = ");
    scanf("%d",&k);
    printf("n = %d", cauchy(k));
    return 0;
}