#include <stdio.h>
#include <math.h>
#include <time.h>

void summe(int i);

int main() {
    clock_t t1,t2;
    printf("Aufwand|an                |bn                |gesamt      |\n");
    printf("-------|------------------|------------------|------------|\n");
    printf("1000   ");
    t1 = clock();
    summe(1000);
    t2 = clock();

    printf("|%f sek|\n", (double)(t2-t1)/CLOCKS_PER_SEC);

    printf("10000  ");
    t1 = clock();
    summe(10000);
    t2 = clock();

    printf("|%f sek|\n", (double)(t2-t1)/CLOCKS_PER_SEC); //100 facher Aufwand
}

void summe(int i)
{

    clock_t t1,t2;
    int n,k;
    double an = 0,bn = 0;

    t1 = clock();
    for (n = 0; n < i; n++)
    {
        an += 1 /pow(n + 1, 2);
    }
    t2 = clock();
    printf("|%.12f sek",(double)(t2-t1)/CLOCKS_PER_SEC);

    t1 = clock();
    for (n=0; n<i; n++) {
        for(k = 0; k < n; ++k) {
            bn += 1 / (pow(k + 1, 2) * pow(n - k + 1, 2));
        }
    }
    t2 = clock();
    printf("|%.12f sek",(double)(t2-t1)/CLOCKS_PER_SEC);
    //printf("an=%.17f, bn=%.17f\n", an,bn); Ausgabe der Werte
}