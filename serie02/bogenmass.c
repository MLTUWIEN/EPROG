#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double bogenmass(double theta);


int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Wrong Argument: ./bogenmass.out [grad]");
        return EXIT_FAILURE;
    }
    if(strtod(argv[1],NULL) <=0 )
        return EXIT_FAILURE;

    printf("Bogenmass betraegt: %f", bogenmass(strtod(argv[1],NULL)));

    return EXIT_SUCCESS;
}

double bogenmass(double theta)
{

    return (fmod(theta,360)*M_PI)/180;
}