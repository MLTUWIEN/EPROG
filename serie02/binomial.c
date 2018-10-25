#include<stdio.h>
#include <stdlib.h>

int binomial(int n, int k);

int main(int argc, char * argv[])
{
    if( argc != 3)
    {
        printf("Wrong Arguments: ./binomial.out [n] [k]");
        return EXIT_FAILURE;
    }
    if(strtol(argv[2],NULL, 10) < 1 || strtol(argv[1],NULL, 10) <= strtol(argv[2],NULL, 10))
        printf("ERROR: Bitte beachten Sie, dass 1<=k<n gelten muss");
    printf("Binomialkoeffizient = %d\n",binomial(strtol(argv[1],NULL, 10), strtol(argv[2],NULL, 10)));

}


int binomial (int n, int k)
{
    if ( k == n || k == 0 )
        return 1;
    else
        return binomial(n-1,k) + binomial(n-1, k-1);
}