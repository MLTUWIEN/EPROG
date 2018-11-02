#include<stdio.h>
#include <stdlib.h>

double powN(double x, int n);

int main(int argc, char * argv[])
{
    if( argc != 3)
    {
        printf("Wrong Arguments: ./powN.out [x] [n]");
        return EXIT_FAILURE;
    }
    printf("pow(x,n) = %f\n",powN(strtol(argv[1],NULL, 10), strtol(argv[2],NULL, 10)));
	
	return EXIT_SUCCESS;

}


double powN(double x, int n)
{
    if (x == 0 && n < 0)
        return 0.0/0.0;
    else if(x == 0)
        return 0;
    if(n < 0) {
        n = abs(n);
        x = 1 / x;
    }
    if(n == 0)
        return 1;
    else
        return x*powN(x,n-1);
}