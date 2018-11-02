#include<stdio.h>
#include <stdlib.h>
#include <mem.h>

double skalarProdukt(double u[3], double v[3]);
void vektorProdukt(double u[3], double v[3], double w[3]);

int main(int argc, char * argv[])
{
    double w[3] = {0,0,0};
    if( argc != 7) {
        printf("Wrong Arguments: ./produkte.out [a] [b] [c] [x] [y] [z]");
        return EXIT_FAILURE;
    }
    double u[3] = {strtod(argv[1],NULL),strtod(argv[2],NULL),strtod(argv[3],NULL)};
    double v[3] = {strtod(argv[4],NULL),strtod(argv[5],NULL),strtod(argv[6],NULL)};

    printf("Skalarprodukt = %f\n",skalarProdukt(u,v));
    vektorProdukt(u,v,w);
    printf("Skalarprodukt = [%f,%f,%f]\n",w[0],w[1],w[2]);

    return EXIT_SUCCESS;
}


double skalarProdukt(double u[3], double v[3])
{
    return u[0]*v[0]+u[1]*v[1]+u[2]*v[2];
}

void vektorProdukt(double u[3], double v[3], double w[3])
{
    w[0] = u[1]*v[2] - u[2]*v[1];
    w[1] = u[2]*v[0] - u[0]*v[2];
    w[2] = u[0]*v[1] - u[1]*v[0];
}