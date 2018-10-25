#include <stdio.h>

#define MAX(x, y) (x >= y ? x : y)
#define MIN(x, y) (x <= y ? x : y)
#define MEDIAN(a,b,c) ((a >= b) ? \
                ((b >= c) ? b : ((a > c) ? c : a)) : \
                ((b > c) ? ((a > c) ? a : c) : b))




int main() {
    double x,y,z;
    printf("Bitte x eingeben: ");
    scanf("%lf",&x);
    printf("Bitte y eingeben: ");
    scanf("%lf",&y);
    printf("Bitte z eingeben: ");
    scanf("%lf",&z);
    printf("Reihenfolge: \n%f \n%f \n%f \n", MAX(MAX(x,y),z), MEDIAN(x,y,z),MIN(MIN(x,y),z));
    return 0;
}