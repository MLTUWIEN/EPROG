#include <stdio.h>
void square(double* x)
{
    double* y = x; //der neu erstellte Wert von double muss noch auf eine Adresse zeigen
    *x = (*y)*(*x); //es soll der Wert geändert werden (*) nicht die Adresse
}
int main(){
    double x=2.1;
    square(&x);
    printf("x^2=%f\n",x);
    return 0;
}