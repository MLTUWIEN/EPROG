#include <stdio.h>
#include <math.h>
#include <assert.h>


double diff(double (*f)(double), double x, double h0, double tau);
double f1(double x);


int main() {

    double x,h0,tau;

    printf("x=");
    scanf("%lf",&x);

    printf("\nh0=");
    scanf("%lf",&h0);

    printf("\ntau=");
    scanf("%lf",&tau);

    printf("\nf'(%f)=%f\n", x, diff(f1, x,h0,tau));

    return 0;
}

double diff(double (*f)(double), double x, double h0, double tau) {
    int i = 1;
    double h, h1;

    assert(tau > 0);
    assert(h0 > 0);


    do {
        h = (f(x + h0) - f(x)) / h0;
        h0 *= 0.5;
        h1 = (f(x + h0) - f(x)) / h0;

    } while ((fabs(h - h1 > tau) || fabs(h) > tau)
             && fabs(h - h1) > tau * fabs(h));
    return h;
}

double f1(double x)
{
    return pow(x,2)+x;
}