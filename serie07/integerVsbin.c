#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

char* integer2bin(int x);

int bin2integer(char *bin);

int main() {
    char * bin;
    int x;
    printf("x=");
    scanf("%d", &x);
    bin = integer2bin(x);
    printf("%d in bin = %s\n", x,bin);
    printf("%s in dez = %d\n", bin, bin2integer(bin));
    return 0;
}

int bin2integer(char *bin)
{
    int i, tmp = 0;

    for(i = 0; i < strlen(bin); i++)
    {
        if(bin[i] == '1')
            tmp += (int) pow(2,i);
    }
    return tmp;
}

char* integer2bin(int x)
{
    int N = (int) log2(x);
    int i;
    char *tmp = malloc((N+1)* sizeof(char));
    assert(tmp != NULL);
    for (i = N; i >= 0; i--) {
        if(pow(2,i) <= x)
        {
            x -= (int) pow(2,i);
            tmp[i] = '1';
        }
        else
            tmp[i] = '0';
    }
    return tmp;
}