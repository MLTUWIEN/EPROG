#include<stdio.h>
#include <stdlib.h>
#define N 20

void fibonacciVec(int v[], int n);

int main(int argc, char * argv[])
{
    int v[N+1];
    fibonacciVec(v, 0);
    printf("%d", v[N]);
    return EXIT_SUCCESS;
}


void fibonacciVec(int v[], int n)
{
    if(n == N+1)
        return;
    if(n == 0){
        v[n] = 0;
        v[n+1] = 1;
        n += 2;
    }
    v[n] = v[n-1] + v[n-2];
    fibonacciVec(v,n+1);
}