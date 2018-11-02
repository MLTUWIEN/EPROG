#include<stdio.h>
#include <stdlib.h>
#include <math.h>

double p(int n);

int main(int argc, char * argv[])
{
    if( argc != 2)
    {
        printf("Wrong Arguments: ./piRekursiv.out [n] ");
        return EXIT_FAILURE;
    }
    printf("PI = %f\n",p(strtol(argv[1],NULL, 10)));
	
	return EXIT_SUCCESS;

}
double p (int n)
{
    if (n <= 0)
        return 4;
    else
        return 4*pow(-1,n)/(2*n+1)+p(n-1);
}