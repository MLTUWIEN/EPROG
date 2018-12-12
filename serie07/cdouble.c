#include "cdouble.h"

cDouble* newC(double zRe, double zIm){
    cDouble* z = malloc(sizeof(cDouble));
    assert(z != NULL);

    setR(z, zRe);
    setI(z, zIm);

    return z;
}

cDouble* delC(cDouble* z){
    free(z);
    z = NULL;
    return z;
}

void setR(cDouble* z, double zRe){
    assert(z != NULL);
    z->re = zRe;
}

void setI(cDouble* z, double zIm){
    assert(z != NULL);
    z->im = zIm;
}

double getR(cDouble* z){
    assert(z != NULL);
    return z->re;
}

double getI(cDouble* z){
    assert(z != NULL);
    return z->im;
}

cDouble* cA(cDouble* z, cDouble* y){
    cDouble* x = newC(getR(z) + getR(y), getI(z) + getI(y));
    return x;
}

cDouble* cS(cDouble* z, cDouble* y){
    cDouble* x = newC(getR(z) - getR(y), getI(z) - getI(y));
    return x;
}

cDouble* cM(cDouble* z, cDouble* y){
    cDouble* x = newC(0, 0);
    setR(x, getR(z) * getR(y) - getI(z) * getI(y));
    setI(x, getR(z) * getI(y) + getI(z) * getR(y));
    return x;
}

cDouble* cD(cDouble* z, cDouble* y){
    assert(getR(y) * getR(y) + getI(y) * getI(y) != 0);
    cDouble* x = newC(0, 0);
    setR(x, (getR(z) * getR(y) + getI(z) * getI(y)) / (getR(y) * getR(y) + getI(y) * getI(y)));
    setI(x, (getI(z) * getR(y) - getR(z) * getI(y)) / (getR(y) * getR(y) + getI(y) * getI(y)));
    return x;
}

double cN(cDouble* z){
    return sqrt(getR(z) * getR(z) + getI(z) * getI(z));
}

cDouble* cC(cDouble* z){
    cDouble* y = newC(getR(z), -getI(z));
    return y;
}

void printC(cDouble* x){
    if(getI(x) < 0){
        printf("%f-i*%f", getR(x), (-1)*getI(x));
    }
    else{
        printf("%f+i*%f", getR(x), getI(x));
    }
}