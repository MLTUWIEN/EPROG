#include <stdio.h>
#include <stdlib.h>

int division(int m, int n);

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        printf("Wrong Arguments: ./divison.out [m] [n]");
        return EXIT_FAILURE;
    }
    printf("%d", division(strtol(argv[1],NULL, 10), strtol(argv[2],NULL,10)));
    return EXIT_SUCCESS;
}

int division(int m, int n)
{
    if(m < n)
        return 0;
    else
        return 1+division(m-n,n);
}