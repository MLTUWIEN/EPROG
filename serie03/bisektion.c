#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tinyexpr.h"

/*
 * TinyExpr supports addition (+), subtraction/negation (-), multiplication (*), division (/), exponentiation (^) and modulus (%) with the normal operator precedence (the one exception being that exponentiation is evaluated left-to-right, but this can be changed - see below).

The following C math functions are also supported:

abs (calls to fabs), acos, asin, atan, atan2, ceil, cos, cosh, exp, floor, ln (calls to log), log (calls to log10 by default, see below), log10, pow, sin, sinh, sqrt, tan, tanh
The following functions are also built-in and provided by TinyExpr:

fac (factorials e.g. fac 5 == 120)
ncr (combinations e.g. ncr(6,2) == 15)
npr (permutations e.g. npr(6,2) == 30)

 Also, the following constants are available:
 pi, e
 */

 /*
  * Funktionen:
  * x+1 --> Nullstelle bei -1 (Intervall egal da linear)
  * x^2-4 --> Nullstelle bei 2 & -2 (Intervall 0 x oder -x 0)
  * x^2+e^x-2 --> Nullstelle ca 0.5 & -1.3 (Intervall 0 x oder -x 0
  */


int bisektion(te_expr *n, double ab[2], double *x, double eps);


int main(int argc, char * argv[])
{
    if( argc != 5)
    {
        printf("Usage: ./bisektion.out \"expression\" [eps] [a] [b]\n");
        return EXIT_FAILURE;
    }
    const char *expression = argv[1];
    printf("Evaluating:\n\t%s\n", expression);

    double ab[2] = {strtod(argv[3],NULL),strtod(argv[4],NULL)};
    double x;
    te_variable vars[] = {{"x", &x}};
    te_expr *n = te_compile(expression, vars, 1, 0); //last param err handling

    int err = bisektion(n,ab,&x,strtod(argv[2],NULL));
    if(err == -1)
        printf("Fehler\n");
    else{
        x = ab[0];
        printf("Nullstelle: %f\n", x);
    }


    return EXIT_SUCCESS;
}


int bisektion(te_expr *n, double ab[2], double *x, double eps)
{
    *x = ab[0];
    double r1 = te_eval(n);
    *x = ab[1];
    double r2 = te_eval(n);
    *x = (ab[0]+ab[1])/2;
    double r3 = te_eval(n);
    printf("Funktionsaufruf: \n a=%f, b=%f, |b-a|=%f, f(c)=%f\n",ab[0],ab[1],fabs(ab[1]-ab[0]), r3);

    if(r1*r2 > 0)
        return -1;
    if(fabs(ab[1]-ab[0]) <= eps)
        return 0;

    if(r1*r3 < 0) {
        ab[1] = (ab[0]+ab[1])/2;
        bisektion(n, ab, x, eps);
    } else if (r1*r3 > 0) {
        ab[0] = (ab[0]+ab[1])/2;
        bisektion(n, ab, x, eps);
    }
    else
        return -1;
}