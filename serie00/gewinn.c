#include <stdio.h>

int main()
{
  double a=0,b=0;
  printf("Gewinn: ");
  scanf("%lf", &a);
  printf("Freunden: ");
  scanf("%lf", &b);
  printf("Pro Person: %f\n",a/(b+1));
  return 0;
}

