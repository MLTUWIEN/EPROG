#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//3,4,5
//56, 90, 106

int cmpfunc(const void *x, const void *y) {
    return (*(double *) x - *(double *) y) <= 0 ? -1 : 1;

    // qsort() expects the comparison function to return:
    //
    //    a negative result if val1 < val2
    //    0 if val1 == val2
    //    a positive result if val1 > val2
}

int main() {
    double values[3];
    printf("Bitte a eingeben:");
    scanf("%lf", &values[0]);
    printf("Bitte b eingeben:");
    scanf("%lf", &values[1]);
    printf("Bitte c eingeben:");
    scanf("%lf", &values[2]);

    if(values[0] <= 0 || values[1] <= 0 || values[2] <= 0)
        return 0;

    qsort(&values, sizeof(values) / sizeof(values[0]), sizeof(double), cmpfunc);

    /*printf("\nAfter sorting the list is: \n");
    for(int n = 0 ; n < 3; n++ ) {
        printf("%f ", values[n]);
    }*/

    if(values[0] + values[1] < values[2])
        printf("unmoegliches Dreieck\n");
    else if(values[0]+values[1] == values[2])
        printf("eindimensionales entartetes Dreieck:");
    else
    {
        if(values[0] == values[1] && values[1] == values[2])
            printf("gleichseitiges Dreieck:");
        else if ((values[0] == values[1]) != (values[1] == values[2]))
            printf("gleichschenkliges Dreieck:");
        else
            printf("%s\n",
               values[0] * values[0] + values[1] * values[1] == values[2] * values[2] ?
               "rechtwinkliges Dreieck" : "unregelmaessiges Dreieck");
    }
    return 0;
}