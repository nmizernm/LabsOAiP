#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);
  // Объявляем переменные
  int n, i, j, min_even, min_even_elem, row, col, choice;
  int matrix[100][100];

  printf("Выберите способ заполнения массива:\n");
  printf("1. Ввести элементы вручную\n");
  printf("2. Заполнить случайными значениями\n");
  scanf("%d", &choice);
  if (choice = 1) {
    // Вводим количество строк и столбцов
    printf("Введите количество строк: ");
    scanf("%d", &n);

    // Вводим значения в матрицу
    printf("Введите значения матрицы:\n");
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf("Введите элемент массива a[%d][%d]: ", i, j);
        scanf("%d", &matrix[i][j]);
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf("%d ", matrix[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("Введите количество строк: ");
    scanf("%d", &n);
    srand(time(NULL));
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        matrix[i][j] = rand() % 100;
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf("%d ", matrix[i][j]);
      }
      printf("\n");
    }
  }

  min_even = -1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i >= j && i >= n - 1 -j) {
        if (matrix[i][j] % 2 == 0) {
          min_even = matrix[i][j];
          break;
        }
      }
    }
  }

  // Ищем минимальный четный элемент в 3-й области
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i >= j && i >= n - 1 -j) {
        if (matrix[i][j] < min_even && matrix[i][j] % 2 == 0) {
          min_even = matrix[i][j];
        }
      }
    }
  }

  // Выводим результаты
  if (min_even == -1) {
    printf("В 3-й области нет четных элементов.\n");
  } else {
    printf("Минимальный четный элемент в 3-й области: %d\n", min_even);
    
  }
  return 0;
}
