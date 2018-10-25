#include <stdio.h>

int main() {
    double l,x,y;
    printf("Bitte ein L eingeben: ");
    scanf("%lf",&l);

    if(l <= 0)
        return 0;

    printf("Bitte ein x eingeben: ");
    scanf("%lf",&x);

    printf("Bitte ein y eingeben: ");
    scanf("%lf",&y);

    if(x <= l && y <= l)
    {
        if(y == 0 | y == l)
            printf("Punkt liegt auf dem Rand");
        else if(x == 0 | x == l)
            printf("Punkt liegt auf dem Rand");
        else
            printf("Punkt liegt im Quadrat");
    }
    else
        printf("Punkt liegt nicht im Quadrat");
    return 0;
}