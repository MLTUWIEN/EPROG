#include <stdio.h>

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
}


void primfaktoren(unsigned int n)
{
    int i = 0;
    int prime[n];
    eratosthenes(prime, n);
    do
    {

        if(prime[i] != 0)
        {
            if(n % prime[i] == 0)
            {
                n = n/prime[i];
                printf("%d, ", prime[i]);
                i--;
            }
        }
        i++;
    }while(n!=1);
}

int main() {
    unsigned int n;
    printf("k = ");
    scanf("%d",&n);
    primfaktoren(n);
    return 0;
}

