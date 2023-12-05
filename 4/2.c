#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);
  // Объявляем переменные
  int n, m, i, j, num_row, first_elem, elem;
  boolean hasZeroElement;
  int matrix[100][100];

  // Вводим количество строк и столбцов
  printf("Введите количество строк: ");
  scanf("%d", &n);
  printf("Введите количество столбцов: ");
  scanf("%d", &m);

  
  // Вводим значения в матрицу
  printf("Введите значения матрицы:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("Введите элемент массива a[%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Проверяем, есть ли в матрице хотя бы одна строка, содержащая элемент, равный нулю
  num_row = -1;
  hasZeroElement = 0;
  for (i = 0; i < n; i++) {
    if (hasZeroElement)
      break;
    for (j = 0; i < m; j++) {
      if (matrix[i][j] == 0) {
        i++;
        first_elem = matrix[i][0];
        num_row = i;
        hasZeroElement = 1;
        break;
      }
    }
  }
  
  // Если в матрице есть такая строка, уменьшаем все элементы матрицы на значение первого элемента найденной строки
  if (num_row != -1) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        matrix[i][j] -= first_elem;
      }
    }
  }

  // Выводим результаты
  if (num_row == -1) {
    printf("В матрице нет строк, содержащих элемент, равный нулю.\n");
  } else {
    printf("В матрице есть строка, содержащая элемент, равный нулю. Номер строки: %d\n", num_row);
    printf("Новые значения матрицы:\n");
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        printf("%d ", matrix[i][j]);
      }
      printf("\n");
    }
  }

}
