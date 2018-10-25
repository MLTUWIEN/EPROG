#include <stdio.h>
#include <stdlib.h>

void quadrant(double x, double y);

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        printf("Wrong Arguments: ./quadrant.out [x] [y]");
        return EXIT_FAILURE;
    }
    quadrant(strtod(argv[1],NULL),strtod(argv[2],NULL));
    return EXIT_SUCCESS;
}

void quadrant(double x, double y)
{
    if(x == 0 || y == 0)
        printf("Der Punkt (%f,%f) liegt auf einer der Achsen.",x,y);
    else
    {
        int q;
        if (x > 0 && y > 0)
            q = 1;
        else if(x < 0 && y > 0)
            q = 2;
        else if(x < 0 && y < 0)
            q = 3;
        else
            q = 4;
        printf("Der Punkt (%f,%f) befindet sich im %d. Quadranten.",x,y,q);
    }
}