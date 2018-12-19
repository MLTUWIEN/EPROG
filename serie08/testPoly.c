//
// Created by markus on 19.12.2018.
//

#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int main()
{
    double f = 0;
    double x = 0;
    int k = 0;
    polynomial* p = NULL;
    polynomial* q = NULL;
    polynomial* r = NULL;

    printf("Einlesen von p:\n");
    p = scanPoly();

    printf("Einlesen von q:\n");
    q = scanPoly();
    r = NULL;

    printf("\nq wird auf Grad 5 gesetzt!\n");
    setPolyDegr(p, 5);
    printf("a5 von p wir auf 4.2 gesetzt!\n");
    setPolyCoef(p, 5, 4.2);

    printPoly(p);
    printf("\n");
    printPoly(q);
    printf("\n");

    printf("\nr = p + q:\n");
    r = addPoly(p, q);
    printPoly(r);
    printf("\n");

    printf("\nr = p * q:\n");
    r = prodPoly(p, q);
    printPoly(r);
    printf("\n");

    printf("Fuer welches x soll p ausgewertet werden? ");
    scanf("%lf", &x);
    f = evalPoly(p, x);
    printf("f(%f) = %f\n", x, f);

    printf("Die wievielte Ableitung von p soll evaluiert werden? ");
    scanf("%d", &k);
    f = diffEvalPoly(p, k, x);
    printf("p(%d)(%f) = %f\n", k, x, f);

    p = delPoly(p);
    q = delPoly(q);
    r = delPoly(r);
    return 0;
}