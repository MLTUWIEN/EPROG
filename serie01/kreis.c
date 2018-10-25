#include <stdio.h>
#include <math.h>

int main()
{
    double r,u,a;
    printf("Bitte geben Sie einen Radius ein: ");
    scanf("%lf", &r);
    a = pow(r,2)*M_PI;
    printf("Der Flaecheninhalt betraegt: %f\n",a);
    u = 2*r*M_PI;
    printf("Der Umfang betraegt: %f\n",u);
    return 0;
}