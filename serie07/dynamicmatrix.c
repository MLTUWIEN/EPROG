
#include "dynamicmatrix.h"

//Allokieren von Speicher fur eine spaltenweise gespeicherte ¨ m × n- Matrix.
double* mallocmatrix(int m, int n) {
    double *matrix = malloc((m * n) * sizeof(double));

    return matrix;
}

//Freigeben des allokierten Speichers einer Matrix.
double* freematrix(double* matrix) {
    free(matrix);
    matrix = NULL;
    return matrix;
}

//Reallokieren des Speichers der Matrix, gegebenenfalls Beibehalten von vorhandenen Eintraegen und
//Initialisieren von neuen Eintraegen mit 0.
double* reallocmatrix(double* matrix, int m, int n, int mNew, int nNew) {
    int i, j;
    assert(mNew > 0);
    assert(nNew > 0);
    double *new_matrix = malloc((mNew * nNew) * sizeof(double));

    for (i = 0; i < mNew; i++) {
        for (j = 0; j < nNew; j++) {
            if (i >= m || j >= n) {
                *(new_matrix + i + j * mNew) = 0;
            } else {
                *(new_matrix + i + j * mNew) = *(matrix + i + j * m);
            }
        }
    }

    freematrix(matrix);
    return new_matrix;
}

void printmatrix(double* matrix, int m, int n){
    int i, j, index;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            index = i + (m * j);
            printf("%f ", matrix[index]);
        }
        printf("\n");
    }
    printf("\n");
}

double* scanmatrix(int m, int n){
    double* matrix = NULL;
    int i,j;

    matrix = mallocmatrix(m, n);

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("a(%d, %d) = ", i + 1, j + 1);
            scanf("%lf",(matrix + i + j * m));
        }
    }

    return matrix;
}

double* cutOffRowJ(double* matrix, int m, int n, int cut_j){
    int i,j;

    double* new_matrix = mallocmatrix(m - 1, n);

    for(i = 0; i < m - 1; i++){
        for(j = 0; j < n; j++){
            if(i >= cut_j - 1){
                *(new_matrix + i + j * (m - 1)) = *(matrix + i + j * m + 1);
            }
            else{
                *(new_matrix + i + j * (m - 1)) = *(matrix + i + j * m);
            }
        }
    }

    freematrix(matrix);
    return new_matrix;
}

double* cutOffColK(double* matrix, int m, int n, int cut_k){
    int i,j;

    double* new_matrix = mallocmatrix(m, n - 1);

    for(i = 0; i < m; i++){
        for(j = 0; j < n - 1; j++){
            if(j >= cut_k - 1){
                *(new_matrix + i + j * m) = *(matrix + i + j * m + m);
            }
            else{
                *(new_matrix + i + j * m) = *(matrix + i + j * m);
            }
        }
    }

    freematrix(matrix);
    return new_matrix;
}

