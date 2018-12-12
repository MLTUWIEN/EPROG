#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int countValueInRow (double** matrix, int m, int n, int val, int row);
int countValueInCol (double** matrix, int m, int n, int val, int col);


int main () {
    int i, j, m, n, row, col, val;
    double** matrix;

    printf("m=");
    scanf("%d" ,&m);
    printf("\nn=");
    scanf("%d" ,&n);

    matrix = malloc(m*sizeof(double*));

    for(i=0 ; i < m ; i++) {
        matrix[i]=malloc(n*sizeof(double));
    }

    printf("\nMatrix\n");

    for (i=0 ; i < m ; i++) {
        for (j=0 ; j < n ; j++) {
            printf("Marix[%d][%d]=" ,i+1,j+1);
            scanf("%lf" ,&matrix[i][j]);
        }
    }

    assert(matrix != NULL);

    printf("val=");
    scanf("%d" ,&val);
    printf("row=");
    scanf("%d" ,&row);
    printf("col=");
    scanf("%d" ,&col);

    assert(row <= m);
    assert(col <= n);

    row -= 1;
    col -= 1;

    printf("Der Wert %d kommt in der Zeile [%d] %d mal und in der "
           "Spalte [%d] %d mal vor.\n" ,val ,(row+1),
           countValueInRow(matrix, m, n, val, row), (col+1),
           countValueInCol(matrix, m, n, val, col));

    return 0;
}

int countValueInRow (double** matrix, int m, int n, int val, int row)
{
    int i, k = 0;

    for (i = 0 ; i < n ; i++) {
        if (matrix[row][i] == val) {
            k++;
        }
    }
    return k;
}
int countValueInCol (double** matrix, int m, int n, int val, int col)
{
    int i,k = 0;

    for (i = 0 ; i < m ; i++) {
        if (matrix[i][col] == val) {
            k++;
        }
    }
    return k;
}
