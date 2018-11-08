#include <stdio.h>
#define N 10
void bubblesort(int array[], int length);


int main() {

    int x[N] = {5,2,8,4,0,1,9,30,79,-4};

    bubblesort(x, N);

    int i;
    for (i = 1; i < N ; i++)
    {
        printf("%d, " ,x[i]);
    }
    printf("\n");
    return 0;
}


void bubblesort(int array[], int length)
{
    int i, j,tmp;

    for (i = 1; i < length ; i++)
    {
        for (j = 0; j < length - i ; j++)
        {
            if (array[j] > array[j+1])
            {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}