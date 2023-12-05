#include <stdio.h>
#include <math.h>
#include <windows.h>
int main()
{
  float a, sum, n;

  sum = 0;
  n = 0;
  SetConsoleOutputCP(CP_UTF8);
  printf("Введите значение переменной a\n");
  scanf("%f", &a);
  while (sum<=a) {
    n++;
    sum = sum + 1.0/n;
    
  }
  
  printf("Наименьшее n %d", (int)n);
  
}