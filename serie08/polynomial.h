//
// Created by markus on 19.12.2018.
//

#ifndef POLYNOMIAL_PLYNOMIAL_H
#define POLYNOMIAL_PLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

struct _polynomial_ {
    double* coef;
    int degr;
};


typedef struct _polynomial_ polynomial;

polynomial* newPoly(int);

polynomial* delPoly(polynomial*);

double getPolyCoef(polynomial*, int);

int getPolyDegr(polynomial*);

void setPolyCoef(polynomial*, int, double);

void setPolyDegr(polynomial*, int);

void printPoly(polynomial*);

polynomial* scanPoly();

polynomial* addPoly(polynomial*, polynomial*);

polynomial* prodPoly(polynomial*, polynomial*);

double evalPoly(polynomial*, double);

double diffEvalPoly(polynomial*, int, double);

// polynomial* taylor(polynomial*, int, double);






#endif //POLYNOMIAL_PLYNOMIAL_H
