#include <stdio.h>
#include <math.h>
#include <windows.h>
main()
{
  SetConsoleOutputCP(CP_UTF8);
  float radius, a;
  printf("Введите значения радиуса и стороны квадрата\n");
  scanf("%f%f", &radius, &a);
  if (2*radius <= a) {
    printf("Круг помещается в квадрате\n");
  }
  else {
    printf("Круг не помещается в квадрате\n");
  }
  if (a*sqrt(2) <= 2*radius) {
    printf("Квадрат помещается в круге");
  }
  else {
    printf("Квадрат не помещается в круге");
  }


}