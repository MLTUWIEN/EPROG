#ifndef CDOUBLE_CDOUBLE_H
#define CDOUBLE_CDOUBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

struct _cDouble_ {
    double re;
    double im;
};

typedef struct _cDouble_ cDouble;

cDouble* newC(double, double);

cDouble* delC(cDouble*);

void setR(cDouble*, double);

void setI(cDouble*, double);

double getR(cDouble*);

double getI(cDouble*);

cDouble* cA(cDouble*, cDouble*);

cDouble* cS(cDouble*, cDouble*);

cDouble* cM(cDouble*, cDouble*);

cDouble* cD(cDouble*, cDouble*);

double cN(cDouble*);

cDouble* cC(cDouble*);

void printC(cDouble*);

#endif //CDOUBLE_CDOUBLE_H
