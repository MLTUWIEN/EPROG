#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main()
{
    int n;
    printf("Bitte einen Index eingeben: ");
    scanf("%d", &n);
    printf("Ergebnis: %d",fibonacci(n));
    return EXIT_SUCCESS;
}

int fibonacci(int n)
{
    if(n<=0)
        return 0;
    else if( n == 1 )
        return 1;
    else
        return fibonacci(n-2)+fibonacci(n-1);
}