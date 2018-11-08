#include <stdio.h>

int verg(int x[10], int y[3]);

int main() {

    int  x[10];
    int y[3];

    int i,erg;
    for(i = 0; i < 10; i++)
    {
        int tmp;
        printf("x%d=",i);
        scanf("%d", &tmp);
        x[i] = tmp;
    }

    for(i = 0; i < 3; i++)
    {
        int tmp;
        printf("y%d=",i);
        scanf("%d", &tmp);
        y[i] = tmp;
    }
    erg = verg(x,y);
    printf("Erg: %d", erg);
    return 0;
}

int verg(int x[10], int y[3])
{
   int i;
   for(i=0; i<7; i++)
   {
       if(x[i] == y[0] && x[i+1] == y[1] && x[i+2] == y[2])
           return 1;
   }
   return 0;
}