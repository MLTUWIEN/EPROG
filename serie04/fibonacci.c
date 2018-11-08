#include <stdio.h>


void fibonacci(int n);

int main()
{
    int n;

    printf("Enter the number of terms\n");
    scanf("%d", &n);
    fibonacci(n);
}

void fibonacci(int n)
{
    int first = 0, second = 1, next, c;

    for (c = 1; c < n; c++)
    {
        next = first + second;
        first = second;
        second = next;
    }
    printf("xk=%d\n", next);
}