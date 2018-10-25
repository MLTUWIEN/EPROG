#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//P(-1|2) Q(3|-6) und R(2|-4)
// P(1,2), Q(3,5) , R(-3,-4)


bool punkte(char *values[]);

int main(int argc, char * argv[])
{
    if(argc != 7)
    {
        printf("Wrong Arguments ./punkte.out [a] [b] [x] [y] [v] [w]");
        return EXIT_FAILURE;
    }
    printf("Die Punkte liegen%s auf einer Geraden.", punkte(argv) ? "":" nicht");
    return EXIT_SUCCESS;
}

bool punkte(char *values[])
{
    //printf("%f\n", (strtod(values[4],NULL)-strtod(values[2],NULL))/(strtod(values[3],NULL)-strtod(values[1],NULL)));
    //printf("%f\n", (strtod(values[6],NULL)-strtod(values[2],NULL))/(strtod(values[5],NULL)-strtod(values[1],NULL)));
    return((strtod(values[4],NULL)-strtod(values[2],NULL))/(strtod(values[3],NULL)-strtod(values[1],NULL)) ==\
        (strtod(values[6],NULL)-strtod(values[2],NULL))/(strtod(values[5],NULL)-strtod(values[1],NULL)));
}
