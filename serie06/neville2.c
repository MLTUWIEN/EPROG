#include <stdio.h>
#include <stdlib.h>

double neville2(double t, double x[], double y[], int n);

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

	printf("\np(%g) = %f", t, neville2(t, x, y, n));

	return 0;

}

double neville2(double t, double x[], double y[], int n){

	int j, m;

	for(m = 1; m < n; m++){

		for(j = 0; j < (n-m); j++){

			y[j] = (t-x[j]) * y[j+1] - (t-x[j+m]) * y[j];
			y[j] /= (x[j+m]-x[j]);
		}

	}

	return y[0];

}






