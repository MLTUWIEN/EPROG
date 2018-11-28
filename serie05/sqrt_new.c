#include <stdio.h>
#include <math.h>
#include <assert.h>

double sqrtNew(double x, double tau)
{
    double x1 = 1./2*(1+x);
    double x2 = 1./2*(x1+x/x1);
    do
    {
        if(x1 <= tau || fabs(x1-x2)/fabs(x1) <= tau)
            return x1;
        x1 = x2;
        x2 = 1./2*(x1+x/x1);
    }while(1);
}


int main() {
    double x;
    double tau;
    printf("x = ");
    scanf("%lf",&x);
assert(x > 0);
    printf("\ntau = ");
    scanf("%lf", &tau);
	double wert = sqrtNew(x,tau);
    printf("\nxn = %f\n", wert);
    printf("sqrt(x) = %f\n", sqrt(x));
    printf("|xn-sqrt(x)| = %f\n", fabs(wert-sqrt(x)));
    return 0;
}