#include <stdio.h>

int get_positive_int(void);

int main(void)
{
  int n = get_positive_int();
  printf("%i\n", n);
}

int get_positive_int(void)
{
  int n;
  do
  {
    printf("Positive Integer: ");
    scanf("%i", &n);
  }
  while (n < 1);

  return n;
}