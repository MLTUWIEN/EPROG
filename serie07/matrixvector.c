#include "dynamicmatrix.h"


double* matrixvector(double* matrix, double* vector, int m, int n);

int main(){
    int m, n;
    double* mat = NULL;
    double* vec = NULL;
    double* res = NULL;

    printf("Bitte geben Sie m ein: ");
    scanf("%d", &m);
    printf("Bitte geben Sie n ein: ");
    scanf("%d", &n);

    printf("\nBitte geben Sie die Elemente Ihrer Matrix an:\n");
    mat = scanmatrix(m, n);
    printmatrix(mat,m,n);
    printf("\nBitte geben Sie die Elemente Ihrer Matrix an:\n");
    vec = scanmatrix(n, 1);
    printmatrix(vec,n,1);

    res = matrixvector(mat, vec, m, n);

    printf("\nDas Ergebnis des Matrix-Vektor-Produktes ist:\n");
    printmatrix(res, m, 1);

    freematrix(mat);
    freematrix(vec);
    freematrix(res);
    return 0;
}

double* matrixvector(double* matrix, double* vector, int m, int n){
    int i,j;
    double* result = mallocmatrix(m, 1);

    for(i = 0; i < m; i++){
        *(result + i) = 0;
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            *(result + i) += *(matrix + i + j * m) * *(vector + j);
        }
    }

    return result;
}