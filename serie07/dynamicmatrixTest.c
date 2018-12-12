#include "dynamicmatrix.h"

int main()
{
    int m,n;

    printf("\nm=");
    scanf("%d", &m);
    printf("\nn=");
    scanf("%d", &n);

    double *matrix = mallocmatrix(m,n);
    matrix = scanmatrix(m,n);
    printmatrix(matrix,m,n);
    matrix = reallocmatrix(matrix, m,n, 3,3);
    matrix = scanmatrix(3,3);
    printmatrix(matrix,3,3);
    matrix = cutOffRowJ(matrix,3,3,2);
    printmatrix(matrix,2,3);
    matrix = cutOffColK(matrix,2,3,0);
    printmatrix(matrix,2,2);


}