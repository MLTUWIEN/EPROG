#include <stdio.h>
#include <assert.h>
#include <math.h>

double diffaitken(double (*fct)(double), double x, double h0, double tau);
double aitken(double x, double y, double z);
double f1(double x);


int main(){

    double x, h0, tau;

    printf("x=");
    scanf("%lf", &x);
    printf("\nh0 = ");
    scanf("%lf", &h0);
    printf("\ntau = ");
    scanf("%lf", &tau);

    printf("\nf'(%g)=%lf", x, diffaitken(f1, x, h0, tau));

    return 0;
}

double diffaitken(double (*fct)(double), double x, double h0, double tau) {

    assert(tau > 0);
    assert(h0 > 0);

    double y, y1, fx[4];

    fx[0] = fct(x);

    fx[1] = (fct(x+h0) - fx[0])/h0;
    h0 *= 0.5;
    fx[2] = (fct(x+h0) - fx[0])/h0;
    h0 *= 0.5;
    fx[3] = (fct(x+h0) - fx[0])/h0;

    y1 = aitken(fx[0], fx[1], fx[2]);

    do{

        y = y1;

        h0 *= 0.5;

        fx[1] = fx[2];
        fx[2] = fx[3];
        fx[3] = (fct(x+h0) - fx[0])/h0;

        y1 = aitken(fx[1], fx[2], fx[3]);

        printf("hn+1 = %f\t|yn-yn+1| = %f\t yn+1 = %f\n", h0, fabs(y-y1), y1);

    }
    while((fabs(y-y1) > tau || fabs(y1) > tau) && (fabs(y-y1) > tau*fabs(y1)));

    return y1;
}

double aitken(double x, double y, double z){

    return x - (((y-x) * (y-x)) / (z - 2*y + x));
}

double f1(double x){
    return pow(x,2) + x;
}

