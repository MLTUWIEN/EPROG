#include <stdio.h>


double scanfpositiv()
{
    double tau;
    do{
        printf("tau=");
        scanf("%lf", &tau);
    }while(tau <= 0);
    return tau;
}


int main()
{
    printf("tau=%f\n",scanfpositiv());

    return 0;
}