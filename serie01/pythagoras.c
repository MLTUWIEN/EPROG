#include <stdio.h>
#include <math.h>
//Tests:
// 3,4,5
// 56,90,106

int main() {

    int a,b,c;
    printf("A eingaben: ");
    scanf("%d", &a);
    printf("B eingaben: ");
    scanf("%d", &b);
    printf("C eingaben: ");
    scanf("%d", &c);

    printf("a = %d, b = %d, c = %d\n", a,b,c);

    double f = pow(a,2) + pow(b,2);
    double g = pow(c,2);

    printf("Es handelt sich%s um ein pythagoraeisches Tripel.", f==g ? "":" nicht");
    return 0;
}