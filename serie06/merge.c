#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* merge(double* a, int m, double* b, int n);

int main(){

    int m, n, i;
    printf("n=");
    scanf("%d", &m);
    printf("m=");
    scanf("%d", &n);

    double a[m], b[n], *c = NULL;

    for (i = 0; i < m; i++){

        printf("a%d = ", i);
        scanf("%lf", &a[i]);
    }

    for (i = 0; i < n; i++){

        printf("b%d = ", i);
        scanf("%lf", &b[i]);
    }

    c = merge(a, m, b, n);

    for (i = 0; i < n+m; i++){

        printf("c[%d] = %lf\n", i, c[i]);
    }

    free(c);
    c = NULL;

    return 0;
}

double* merge(double* a, int m, double* b, int n){

    int i = 0, j = 0, k = 0;

    double *c = NULL;
    c = malloc((n+m)*sizeof(double));
    assert(c != NULL);

    while (i < m && j < n){

        if (a[i] <= b[j]){

            c[k] = a[i];
            i++;
        }
        else{

            c[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < m){

        c[k] = a[i];
        i++;
        k++;
    }

    while (j < n){

        c[k] = b[j];
        j++;
        k++;
    }
    return c;
}



