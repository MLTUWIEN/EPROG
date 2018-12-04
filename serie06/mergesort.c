#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void mergesort(double* x, int n);

int main(){

	double *x;
	int n, i;

	printf("n =");
	scanf("%d", &n);
	assert(n >= 1);
	x = malloc(n*sizeof(double));

	for(i = 0; i < n; i++){

		printf("x%d = ", i);
		scanf("%lf", &x[i]);
	}

	mergesort(x, n);

	for(i = 0; i < n; i++){

		printf("x%d=%f\n", i, x[i]);
	}

	free(x);
	x = NULL;

	return 0;
}

void mergesort(double* x, int n){

	if(n < 2){
		return;
	}
	if(n == 2){

		if(*x > *(x+1)){

			double temp = *x;
			*x = *(x+1);
			*(x+1) = temp;

		}
		return;
	}

	int m = n-(n/2);

	double *z = x + m;
	double *y = x;

	mergesort(y, m);
	mergesort(z, n/2);


	int i = 0, j = 0, k = 0;
	double a[m], b[n/2];


	for (i = 0; i < m; i++){

        a[i] = y[i];
	}

    for (i = 0; i < n/2; i++){

        b[i] = z[i];
	}

	i = 0;

	while (i < m && j < n/2){

        if (a[i] <= b[j]){

            x[k] = a[i];
            i++;
        }
        else{

            x[k] = b[j];
            j++;
        }
        k++;
    }

	while (i < m){

        x[k] = a[i];
        i++;
        k++;
    }

    while (j < n/2){

        x[k] = b[j];
        j++;
        k++;
    }

}

