#include <stdio.h>
#include <stdlib.h>

double neville(double, double[], double[], int);

int main(){

	double t;

	printf("t = ");
	scanf("%lf", &t);


	//Polynom = x^4 - 4x^3 + 4x^2 +5
	//p(6) = 581
	//p(12) = 14405
	int n = 5;
	double x[5] = {-1, 0, 1, 2, 4};
	double y[5] = {14, 5, 6, 5, 69};

	printf("\np(%g) = %f", t, neville(t, x, y, n));

	return 0;

}

double neville(double t, double x[], double y[], int n){

	double **matrix = malloc(n*sizeof(double*));
	double *y1 = malloc(n*sizeof(double));
	int i, m;

	for(i = 0; i < n; i++){
		y1[i] = y[i];
	}

	matrix[0] = y1;

	for(m = 1; m < n; m++){

		double *ym = malloc((n-m)*sizeof(double));

		matrix[m] = ym;

		int j;

		for(j = 0; j < (n-m); j++){

			ym[j] = (t-x[j]) * matrix[m-1][j+1] - (t-x[j+m]) * matrix[m-1][j];
			ym[j] /= (x[j+m]-x[j]);

		}

	}

	double tmp = matrix[n-1][0]; //p_n_j

	for(i = 0; i < n; i++){

		free(matrix[i]);
	}

	free(matrix);

	return tmp;

}






