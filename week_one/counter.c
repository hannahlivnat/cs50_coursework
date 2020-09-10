#include <stdio.h>

int main(void) 
{
  int x = 0;
  printf("what should x be?\n");
  scanf("%i", &x);
  int y = 1;
  if (x < y)
  {
    printf("x is less than y\n");
  }
  else if (x > y)
  {
    printf("x is greater than y\n");
  } else 
  {
    printf("x is equal to y\n");
  }

  while (x < y)
  {
    printf("Hello\n");
    x++;
  }

  int i = 0;
  while (i < 5)
  {
    printf("Hello world\n");
    i++;
  }

  for (int counter = 0; counter < 5; counter++)
  {
    printf("looping\n");
  }

  int age;
  printf("What's your age?\n");
  scanf("%i", &age);
  age = age * 365;
  printf("You are at least %i years old.\n", age);

  float price;
  printf("What's the price?\n");
  scanf("%f", &price);
  printf("The price is %.2f.\n", price * 1.0625);

  int n;
  printf("n: \n");
  scanf("%i", &n);

  if (n % 2 == 0)
  {
    printf("%i is even\n", n);
  }
  else
  {
    printf("%i is even\n", n);
  }
}