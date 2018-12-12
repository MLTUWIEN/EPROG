#include <stdio.h>
#include <stdlib.h>
#include "cdouble.h"

int main(){
    cDouble* y = newC(0, 0);
    cDouble* z = newC(0, 0);
    cDouble* x = NULL;
    double tmp;

    printf("y:\n");
    printf("Re(y) = ");
    scanf("%lf", &tmp);
    setR(y, tmp);
    printf("Im(y) = ");
    scanf("%lf", &tmp);
    setI(y, tmp);
    printf("z:\n");
    printf("Re(z) = ");
    scanf("%lf", &tmp);
    setR(z, tmp);
    printf("Im(z) = ");
    scanf("%lf", &tmp);
    setI(z, tmp);

    printf("\n|y| = %f\n", cN(y));
    printf("|z| = %f\n\n", cN(z));

    x = cA(y, z);
    printf("y + z = ");
    printC(x);
    printf("\n");

    x = cS(y, z);
    printf("y - z = ");
    printC(x);
    printf("\n");

    x = cM(y, z);
    printf("y * z = ");
    printC(x);
    printf("\n");

    if(cN(z) != 0){
        x = cD(y, z);
        printf("y / z = ");
        printC(x);
        printf("\n");
    }
    else{
        printf("z = 0\n");
    }

    y = delC(y);
    z = delC(z);
    x = delC(x);
    return 0;
}