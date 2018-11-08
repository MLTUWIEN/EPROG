#include <stdio.h>
#include <math.h>
#define N 5


void maxminmean(int x[], int size);

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
    maxminmean(x, N);
    return 0;
}

void maxminmean(int x[], int size)
{
    int i,min = x[0],max = x[0],mean = 1;
    for(i = 0; i< size; i++)
    {
        mean = mean * x[i];
    }
    for(i = 1; i < size; i++)
    {
        if(min > x[i])
            min = x[i];
        if(max < x[i])
            max = x[i];
    }
    printf("mean=%f,max=%d,min=%d\n", (double) pow(mean,(double)1/size),max,min);
}