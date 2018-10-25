#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double erg;
    printf("Bitte n eingaben: \n");
    scanf("%d",&n);
    erg = pow(-1,n)/(n+2);
    printf("Folgeglied: %f\n", erg);
    return 0;
}