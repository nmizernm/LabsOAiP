#include <stdio.h>
#include <math.h>
#include <windows.h>
int main()
{
  int sum, n, proisvidenie, a;
  proisvidenie = 1;
  sum = 0;
  a = 3;
  n = 0;
  SetConsoleOutputCP(CP_UTF8);
  while (n<=1){
    printf("Введите натуральное значение переменной n>1\n");
    scanf("%d", &n);

  }
  while (a<=n){
    if (a%3 == 0){
        sum += a;
        proisvidenie *= a;
    }
    a++;
  }
  printf("%d %d", sum, proisvidenie);

}
  