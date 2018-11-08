#include <stdio.h>
#include <math.h>
#define N 5


void geomean(int x[], int size);

int main()
{
    int x[N];
    int i;
    for(i = 0; i < N; i++)
    {
        int tmp;
        printf("x%d=",i);
        scanf("%d", &tmp);
        x[i] = tmp;
    }
    geomean(x, N);
    return 0;
}

void geomean(int x[], int size)
{
    int i,mean = 1;
    for(i = 0; i< size; i++)
    {
        mean = mean * x[i];
    }
    printf("mean=%f\n", (double) pow(mean,(double)1/size));
}