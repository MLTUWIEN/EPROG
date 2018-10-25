#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, int i, int k, int j);


int main()
{
    int m;
    printf("Bitte ein n eingeben:");
    scanf("%d", &m);
    hanoi(m,1,2,3);
    return EXIT_SUCCESS;
}

void hanoi(int n, int i, int k, int j)
{
    if(n==1)
        printf("Eine Scheibe wandert vom %d. zum %d. Pfosten.\n", i,j);
    else
    {
        hanoi(n-1, i,j,k);
        hanoi(1, i,k,j);
        hanoi(n-1,k,i,j);
    }
}

