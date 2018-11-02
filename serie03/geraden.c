#include<stdio.h>
#include <stdlib.h>
#include <math.h>

//ident (1,1,1) (2,2,2)
//parallel (1,2,3) (2,4,8)
//schnittpunkt (1,2,3) (-1,2,3) s[0,1.5]
//Schnittpunkt (1,2,3) (-6,7,8) s[0.263158,1.368421]

int geraden(double u[3], double v[3], double s[2]);

int main(int argc, char * argv[])
{
    double s[2] = {0,0};
    if( argc != 7)
    {
        printf("Wrong Arguments: ./geraden.out [a][b] [c] [d] [e] [f]");
        return EXIT_FAILURE;
    }
    double u[3] = {strtod(argv[1],NULL),strtod(argv[2],NULL),strtod(argv[3],NULL)};
    double v[3] = {strtod(argv[4],NULL),strtod(argv[5],NULL),strtod(argv[6],NULL)};
    int erg = geraden(u,v,s);
    printf("Die Geraden sind %s.\n", erg == 1 ? "parallel" : (erg ==0 ? "ident" : "scheidend"));
    if(erg == -1)
        printf("Die Schnittpunkte sind s[%f,%f].\n", s[0],s[1]);

    return EXIT_SUCCESS;

}


int geraden(double u[3], double v[3], double s[2])
{
    if(u[0]/u[1] == v[0]/v[1])
        if(u[2]/u[1] == v[2]/v[1])
            return 0;
        else
            return 1;
    else
    {
        s[0] = -(u[1]*v[2]-u[2]*v[1])/(u[0]*v[1]-u[1]*v[0]);
        s[1] = (u[0]*v[2]-u[2]*v[0])/(u[0]*v[1]-u[1]*v[0]);
        return -1;
    }
}