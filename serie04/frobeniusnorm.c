#include <stdio.h>
#include <math.h>
#define M 5
#define N 5


void frobeniusnorm(double x[M][N], int m,int n);

int main()
{

    double x[M][N];
    int i,j;
    for(i = 0; i < M; i++)
    {
        for(j=0; j < N; j++)
        {
            double tmp;
            printf("x%d%d=",i,j);
            scanf("%lf", &tmp);
            x[i][j] = tmp;
        }
    }
    frobeniusnorm(x, M,N);
    return 0;
}

void frobeniusnorm(double x[M][N], int m, int n)
{
    int i, j;
    double a = 0;
    for(i = 0; i < M; i++)
    {
        for(j=0; j < N; j++)
        {
          a += (x[i][j])*(x[i][j]);
        }
    }
    a = sqrt(a);
    printf("Frobeniusnorm: %f", a);
}