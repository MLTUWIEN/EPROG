#include <stdio.h>

#define NMAX 1000

void eratosthenes(int liste[], int max)
{
    int i,zahl,tmp =2;
    for(i=0; i < max-1; i++)
    {
        liste[i] = i+2;
    }
    do {
        zahl = tmp;
        for (i = tmp-1; i < max-1; i++) {
            if (liste[i] % zahl == 0)
                liste[i] = 0;
            else
            if(zahl == tmp)
                tmp = liste[i];
        }
    }while(zahl != tmp);
    zahl = 0;
    for(i = 0; i < max-1; i++)
    {
        if(liste[i] != 0)
        {
            zahl++;
            printf("%d,", liste[i]);
        }
    }
    printf("\nAnzahl=%d",zahl);
}

int main() {
    int l[NMAX-1];
    eratosthenes(l, NMAX);
    return 0;
}