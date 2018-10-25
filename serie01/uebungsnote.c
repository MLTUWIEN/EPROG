#include <stdio.h>

int main()
{
    int n;
    printf("Bitte gekreutze Beispiele eingeben: ");
    scanf("%d", &n);
    if(n > 80)
        return 0;
    printf("Ihr erreichter Prozentsatz: %.2f%%\n", (double) n/80);
    printf("Sie haben eine %s Note.", ((double)n/80 >= 0.5) ? "positive":"negative");
    return 0;
}