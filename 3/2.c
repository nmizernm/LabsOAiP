#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);
  int n, i, j, min, max, choice, indmax, indmin, temp1, temp2;
  int a[100];

  printf("Выберите способ заполнения массива:\n");
  printf("1. Ввести элементы вручную\n");
  printf("2. Заполнить случайными значениями\n");
  scanf("%d", &choice);
  if (choice = 1) {
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Введите элемент массива a[%d]: ", i);
        scanf("%d", &a[i]);
    }
  } else {
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
  }

  
  max = a[0];
  for (i = 1; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
      indmax = i;
    }
  }
  temp1 = indmax;

  min = a[0];
  for (i = 1; i < n; i++) {
    if (a[i] <= min) {
      min = a[i];
      indmin = i;
    }
  }
  temp2 = indmin;
  for (int i = 0; i<=n-indmin; i++) {
    indmax++;
    a[indmax] = a[indmin];
    indmin++;
  }
  printf("Массив после удаления последовательности:\n");
  
  for (int i = 0; i < temp1+1+n-temp2; i++) {
    printf("%d ", a[i]);

  }
  printf("\n");
  return 0;
}