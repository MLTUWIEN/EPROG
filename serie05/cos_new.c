#include <stdio.h>
#include <math.h>

double cosNew(double x, double tau)
{
    double nenner = 1, i = 2;
    double zaehler = 1, j = x*x;
    double cn = 1,cn1=0;
    do
    {
        zaehler *= j*(-1);
        nenner *= i*(i-1);
        cn += zaehler/nenner;

        if(fabs(cn) <= tau || fabs(cn-cn1)/fabs(cn) <= tau)
            return cn;

        cn1 = cn;
        i += 2;
    }while(1);
}


int main() {
    double x;
    double tau;
    printf("x = ");
    scanf("%lf",&x);
    printf("\ntau = ");
    scanf("%lf", &tau);
    double wert = cosNew(x,tau);
    printf("\ncn = %f\n", wert);
    printf("cos(x) = %f\n", cos(x));
    printf("|cn-cos(x)|= %f\n", fabs(wert-cos(x)));
    if(cos(x)!=0)
        printf("|cn-cos(x)|/|cos(x)| = %f\n", fabs(wert-cos(x))/fabs(cos(x)));
    return 0;
}