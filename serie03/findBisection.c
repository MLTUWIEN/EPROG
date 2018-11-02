#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/* interpolation:
 * avg: O(log(log(n)))
 * worst case: O(sqrt(n)
 * binary search:
 * avg: O(log(n)
 * worst case: O(log(n)*/


int interpolation(int v[], int y, int l, int r);


int main(int argc, char * argv[])
{
    if( argc != 3)
    {
        printf("Wrong Arguments: ./findBisection.out [n] [y]");
        return EXIT_FAILURE;
    }
    int v[strtol(argv[1],NULL,10)];
	
	int i;
    for(i = 0; i < strtol(argv[1],NULL,10); i++)
    {
        v[i] = i;
        printf("%d\n",v[i]);
    }
    int erg = interpolation(v, strtol(argv[2],NULL,10),0, strtol(argv[1],NULL,10)-1);
    if(erg >= 0)
        printf("Searched item is: v[%d] = %d", erg, v[erg]);
    else
        printf("Item not found");
    return EXIT_SUCCESS;
}


int interpolation(int v[], int y, int l, int r)
{
    printf("Funktionsaufruf\n");
    int k;
    if(l <= r) {
        k = (int) round(l + (double)(y - v[l]) / (v[r] - v[l]) * (r - l));
        if (v[k] == y)
            return k;
        else if (v[k] > y)
            return interpolation(v, y, l, k-1);
        else
            return interpolation(v, y, k + 1, r);
    }
    else
        return -1;
}