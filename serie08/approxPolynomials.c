//
// Created by markus on 19.12.2018.
//
#include "polynomial.h"

int binomial(int n, int k);
polynomial* taylorApprox(polynomial* p, int n, double x0);

int main(){

    int n;
    double x;

    polynomial* p = NULL;
    polynomial* taylor = NULL;

    p = scanPoly();

    printf("\nUm welche Stelle wollen Sie das Polynom approximieren?\nx = ");
    scanf("%lf", &x);

    printf("Welchen Grad soll die Taylor-Approximation haben?\nn = ");
    scanf("%d", &n);

    printf("\np = ");
    printPoly(p);

    taylor = taylorApprox(p, n, x);

    printf("\nTaylor-Polynom = ");
    printPoly(taylor);

    p = delPoly(p);
    taylor = delPoly(taylor);

    return 0;
}


//Taylor-Formel - Approximation von Polynom
polynomial* taylorApprox(polynomial* p, int n, double x0){

    assert (p != NULL);
    assert (n >= 0);

    polynomial* taylor = newPoly(n);
    assert(taylor != NULL);

    int kFact = 1;
    int k = 0;
    double ableitung;
    double bruch_gesamt;
    int i, j;

    for(i = 0; i <= n; i++){

        ableitung = diffEvalPoly(p, i, x0);
        bruch_gesamt = ableitung/kFact;

        for(j = 0; j <= i; j++){

            double a = getPolyCoef(taylor, j);
            int bin = binomial(k, j);

            if((k-j)%2 == 1){
                bin *= -1;
            }

            a += bruch_gesamt*pow(x0, (i-j))*bin;
            setPolyCoef(taylor, j,a);
        }

        k++;
        kFact *= k;
    }

    return taylor;
}

//Funktion zur Berechnung des Binomalkoeffizienten.
int binomial(int n, int k){

    if(k == 0 || n == k){
        return 1;
    }

    else if(k == 1){
        return n;
    }

    else{
        return (n*binomial(n-1, k-1)/k);
    }
}