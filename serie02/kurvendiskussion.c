#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void kurvendiskussion(double a, double b, double c);

int main(int argc, char * argv[]) {
    if (argc != 4)
    {
        printf("Wrong arguments: ./kurvendiskurssion.out [a] [b] [c]");
        return EXIT_FAILURE;
    }
    kurvendiskussion(strtod(argv[1],NULL),strtod(argv[2],NULL),strtod(argv[3],NULL));
    return EXIT_SUCCESS;
}

void kurvendiskussion(double a, double b, double c)
{
    if(a == 0)
    {
        printf("Die Nullstelle ist n = (%f,0)\n", -c/b);
        printf("Geraden besitzen keinen Extremwert.\n");
    }
    else
    {
        double dis = pow(b,2)-4*a*c; //Diskriminante
        printf("Nullstelle: ");
        if(dis < 0)
            printf("Keine Loesung in R.\n");
        else if( dis == 0)
        {
            printf("Die doppelte Loesung betraegt: (%f,0)\n\n", -b/(2*a));
        }
        else
        {
            printf("Die Loesungen betragen: x1 = (%f,0), x2 = (%f,0)\n\n", (-b+sqrt(dis))/(2*a),(-b-sqrt(dis))/(2*a));
        }
        printf("Die Xtremstelle ist ein %s und liegt bei (%f,%f)\n", a > 0 ? "Minimum" : "Maximum", -b/(2*a),a*pow(-b/(2*a),2)+b*-b/(2*a)+c);
    }

}
