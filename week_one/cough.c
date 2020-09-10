#include <stdio.h>

//initialize functions at the top
void cough(int n);

int main(void)
{
  cough(3);
}

void cough(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("cough\n");
  }
}