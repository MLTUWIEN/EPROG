#include "polynomial.h"


polynomial* newPoly(int degr){
    polynomial* poly = malloc(sizeof(polynomial));
    int i = 0;

    assert(poly != NULL);

    poly->degr = degr;
    poly->coef = malloc((degr + 1) * sizeof(double));

    for(i = 0; i < degr+1; i++){
        *(poly->coef + i) = 0;
    }

    return poly;
}

polynomial* delPoly(polynomial* poly){
    assert(poly != NULL);

    if(poly->coef != NULL){
        free(poly->coef);
    }
    free(poly);

    return NULL;
}

void setPolyCoef(polynomial* poly, int n, double a){
    assert(poly != NULL);
    if(n > getPolyDegr(poly)){
        setPolyDegr(poly, n);
    }
    *(poly->coef + n) = a;
}

void setPolyDegr(polynomial* poly, int n){
    int old_n = getPolyDegr(poly);
    int i = 0;
    poly->degr = n;
    poly->coef = realloc(poly->coef, (n + 1) * sizeof(double));
    for(i = old_n + 1; i <= n; i++){
        setPolyCoef(poly, i, 0);
    }
}

double getPolyCoef(polynomial* poly, int n){
    if(n > getPolyDegr(poly))
        return 0;

    return *(poly->coef + n);
}

int getPolyDegr(polynomial* poly){
    return poly->degr;
}

polynomial* scanPoly(){
    int n = 0;
    int i = 0;
    double ai = 0;
    polynomial* p = NULL;

    printf("Von welchem Grad ist Ihr Polynom? ");
    scanf("%d", &n);

    p = newPoly(n);

    for(i = 0; i <= n; i++){
        printf("a%d = ", i);
        scanf("%lf", &ai);
        setPolyCoef(p, i, ai);
    }

    return p;
}

void printPoly(polynomial* poly){
    int i = 0;
    double ai = 0;

    for(i = getPolyDegr(poly); i > 0; i--){
        ai = getPolyCoef(poly, i);
        printf("%f*x^%d + ", ai,i);
    }

    printf("%f", getPolyCoef(poly, 0));
}

polynomial* addPoly(polynomial* p, polynomial* q){
    int n,i;
    polynomial* r = NULL;

    if(getPolyDegr(p) >= getPolyDegr(q))
        n = getPolyDegr(p);
    else
        n = getPolyDegr(q);

    r = newPoly(n);

    for(i = 0; i <= n; i++){
        setPolyCoef(r, i, (getPolyCoef(p, i) + getPolyCoef(q, i)));
    }

    return r;
}

polynomial* prodPoly(polynomial* p, polynomial* q){
    int n,i,j;
    polynomial* r = NULL;

    n = getPolyDegr(p) + getPolyDegr(q);

    r = newPoly(n);

    for(i = 0; i <= getPolyDegr(p); i++){
        for(j = 0; j <= getPolyDegr(q); j++){
            setPolyCoef(r, i + j, getPolyCoef(r, i + j) + getPolyCoef(p, i) * getPolyCoef(q, j));
        }
    }

    return r;
}

double evalPoly(polynomial* p, double x){
    int i;
    double f = 0;

    for(i = getPolyDegr(p); i >= 0; i--){
        f += getPolyCoef(p, i) * pow(x, i);
    }

    return f;
}

double diffEvalPoly(polynomial* p, int k, double x){
    int i,j;
    double f = 0;
    double coef;

    for(i = k; i <= getPolyDegr(p); i++){
        coef = getPolyCoef(p, i);
        for(j = i; j > i - k; j--){
            coef *= j;
        }
        f += coef * pow(x, i - k);
    }

    return f;
}

// polynomial* taylor(polynomial* p, int n, double x0){
//   int fac_k = 1;
//   int i = 0;
//   polynomial* tay = newPoly(n);
//   setPolyCoef(tay, 0, )
//
//   for(int i = 1; i <= n; i++){
//
//   }
//
// }