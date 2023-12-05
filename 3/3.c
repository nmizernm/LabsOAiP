#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);
  int n1, n2, i, j, k, choice;
  int a1[100], a2[100], a3[100];
  printf("Выберите способ заполнения массива:\n");
  printf("1. Ввести элементы вручную\n");
  printf("2. Заполнить случайными значениями\n");
  scanf("%d", &choice);


  if (choice = 1) {
    printf("Введите количество элементов первого массива: ");
    scanf("%d", &n1);
    printf("Введите количество элементов второго массива: ");
    scanf("%d", &n2);
    for (i = 0; i < n1; i++) {
        printf("Введите элемент массива a1[%d]: ", i);
        scanf("%d", &a1[i]);
    }
    for (i = 0; i < n2; i++) {
        printf("Введите элемент массива a2[%d]: ", i);
        scanf("%d", &a2[i]);
    }
} else {
    printf("Введите количество элементов первого массива: ");
    scanf("%d", &n1);
    printf("Введите количество элементов второго массива: ");
    scanf("%d", &n2);
    srand(time(NULL));
    for (i = 0; i < n1; i++) {
        a1[i] = rand() % 100;
    }
    for (i = 0; i < n2; i++) {
        a2[i] = rand() % 100;
    }
}

  k = 0;
  for (i = 0; i < n1; i++) {
    a3[k++] = a1[i];
  }
  for (i = 0; i < n2; i++) {
    a3[k++] = a2[i];
  }

  for (i = 0; i < k - 1; i++) {
    for (j = 0; j < k - i - 1; j++) {
      if (a3[j] < a3[j + 1]) {
        int tmp = a3[j];
        a3[j] = a3[j + 1];
        a3[j + 1] = tmp;
      }
    }
  }

  printf("Объединенный массив в порядке убывания:\n");
  for (i = 0; i < k; i++) {
    printf("%d ", a3[i]);
  }
  printf("\n");

  return 0;
}
