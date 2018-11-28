#include <stdio.h>

void charPointerAbstand(char* anfangsadresse, char* endadresse)
{
    printf("Anfangsadresse: %p\n", anfangsadresse);
    printf("Endadresse: %p\n",  endadresse);
    printf("Differenz: %d\n", (long)endadresse-(long)anfangsadresse);

}
void doublePointerAbstand(double* anfangsadresse, double* endadresse)
{
    printf("Anfangsadresse: %p\n", anfangsadresse);
    printf("Endadresse: %p\n",  endadresse);
    printf("Differenz: %d\n", (long)endadresse-(long)anfangsadresse);

}
void shortPointerAbstand(short* anfangsadresse, short* endadresse) {
    printf("Anfangsadresse: %p\n", anfangsadresse);
    printf("Endadresse: %p\n", endadresse);
    printf("Differenz: %d\n", (long) endadresse - (long) anfangsadresse);

}
void intPointerAbstand(int* anfangsadresse, int* endadresse)
{
    printf("Anfangsadresse: %p\n", anfangsadresse);
    printf("Endadresse: %p\n",  endadresse);
    printf("Differenz: %d\n", (long)endadresse-(long)anfangsadresse);

}
void longPointerAbstand(long* anfangsadresse, long* endadresse)
{
    printf("Anfangsadresse: %p\n", anfangsadresse);
    printf("Endadresse: %p\n",  endadresse);
    printf("Differenz: %d\n", (long)endadresse-(long)anfangsadresse);

}


int main() {
    char c[2];
    double a[2];
    short s[2];
    int i[2];
    long l[2];
    charPointerAbstand(&c[0],&c[1]);
    charPointerAbstand(c,c+1);
    doublePointerAbstand(&a[0],&a[1]);
    doublePointerAbstand(a,a+1);
    shortPointerAbstand(&s[0],&s[1]);
    shortPointerAbstand(s,s+1);
    intPointerAbstand(&i[0],&i[1]);
    intPointerAbstand(i,i+1);
    longPointerAbstand(&l[0],&l[1]);
    longPointerAbstand(l,l+1);

    return 0;
}