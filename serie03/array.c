#include<stdio.h>
#include <stdlib.h>
#include <mem.h>

void createVector(int v[], int n, int ende);
void printVector(int v[], int n, int ende);

int main(int argc, char * argv[])
{
    if( argc != 2) {
        printf("Wrong Arguments: ./array.out [n]");
        return EXIT_FAILURE;
    }
    int v[strtol(argv[1],NULL, 10)];
    createVector(v,0,strtol(argv[1],NULL, 10));
    printVector(v,0,strtol(argv[1],NULL, 10));
    return EXIT_SUCCESS;
}


void createVector(int v[], int n, int ende)
{
    if(n == ende)
       return;
    v[n] = n;
    createVector(v, n+1, ende);
}
void printVector(int v[], int n, int ende)
{
    if(n == ende)
        return;
    printf("V[%d]: %d\n",  n, v[n]);
    printVector(v,n+1,ende);
}