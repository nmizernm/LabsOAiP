#include <stdio.h>
#include <windows.h>
int main()
{
  SetConsoleOutputCP(CP_UTF8);
  int a, b, c;
  printf("Введите значения переменных\n");
  scanf("%d%d%d", &a, &b, &c);
  if (a == -b || a == -c || b == -c) {
    printf("Среди чисел a, b и c присутствуют взаимно противоположные числа");

  }
  else{
    printf("Среди чисел a, b и c отсутствуют взаимно противоположные числа");
  }
  

}