#include <stdio.h>
int main(){
    int vec[5] = {1, 3, 5, 7, 9};
    int i = 0;
    for(i=0; i<5; i++){
        printf("0) %p: %d\n", vec[i], (vec+i));
        printf("1) %p: %d\n", (vec+i), vec[i]);
        printf("2) %p: %d\n", &vec[i], *(vec+i));
        printf("3) %p: %d\n\n", &vec[i], *vec+i);
    }
}