#include <stdio.h>

double powN(double x, int n);

int main() {

    double erg, x;
    int n;
    printf("x=");
    scanf("%lf", &x);
    printf("n=");
    scanf("%d", &n);
    erg = powN(x,n);
    printf("Erg: %f", erg);
    return 0;
}

double powN(double x, int n)
{
    double erg = 1;
    if(x==0 && n <=0)
        return 0;
    else if(n==0)
        return 1;
    if(n < 0)
    {
        n = -n;
        x = 1/x;
    }
    int i;
    for(i=1; i <=n; i++)
    {
        erg = erg * x;
    }
    return erg;
}