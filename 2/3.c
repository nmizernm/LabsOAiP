#include <stdio.h>
#include <math.h>
#include <windows.h>
int main()
{
  float A, X;
  int N, a, fct;
  a = 0;
  A = 0.0;
  N = 0;
  SetConsoleOutputCP(CP_UTF8);
  while (N<=0){
    printf("Введите числа X и N\n");
    scanf("%f%d", &X, &N);
  }

  int factorial(int count){
    fct=1;
    for (int i=1;i<=count;i++){
        fct=fct*i;
    }
    return fct;
  }
  while (a<=N){
    A = A + pow(-1, a)*pow(X, 2*a+1)/factorial(2*a+1);
    a++;
  }
  printf("%f", A);
}