#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>


double* aitken(double* x, int n);


int main() {
    double *x, *y;
    int n,i;
    printf("n=");
    scanf("%d", &n);

    x = malloc(n*sizeof(double));
    for(i = 0; i < n; i++)
    {
        printf("\nx%d=",i);
        scanf("%lf", &x[i]);
    }

    y = aitken(x,n);

    for(i=0; i < n-2; i++)
    {
        printf("\ny%d=%f;", i, y[i]);
    }

    free(x);
    free(y);
    x=NULL;
    y=NULL;

    return 0;
}

double* aitken(double* x, int n)
{
    assert(n>=3);

    int i;
    double *y = malloc((n-2)* sizeof(double));

    for(i = 0; i < n-2; i++)
    {

        y[i] = x[i] - (pow((x[i+1] - x[i]),2)/(x[i+2]-2*x[i+1]+x[i]));
        printf("%f",(pow((x[i+1] - x[i]),2))/(x[i+2]-2*x[i+1]+x[i]));
    }
    return y;
}