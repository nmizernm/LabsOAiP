#include <stdio.h>
#include <math.h>
#include <windows.h>
int main()
{
  int b, q, n, a, sum;
  SetConsoleOutputCP(CP_UTF8);
  printf("Введите значения переменных\n");
  scanf("%d%d%d", &b, &q, &n);
  a = pow(q,n);
  sum = (b*(a-1))/(q-1);
  printf("Сумма членов геометрической прогрессии %d", sum);
  
}