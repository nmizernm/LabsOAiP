#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
  // Объявляем переменные
  SetConsoleOutputCP(CP_UTF8);
  int n, m, i, j, count_zero, max_len, max_len_row, max_len_row_ind;
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

  // Считаем количество столбцов, содержащих хотя бы один нулевой элемент
  count_zero = 0;
  for (j = 0; j < m; j++) {
    for (i = 0; i < n; i++) {
      if (matrix[i][j] == 0) {
        count_zero++;
        break;
      }
    }
  }

  // Считаем длину самой длинной серии одинаковых элементов в каждой строке
  max_len_row = 1;
  for (i = 0; i < n; i++) {
    max_len = 1;
    for (j = 1; j < m; j++) {
      if (matrix[i][j] == matrix[i][j - 1]) {
        max_len++;
      }
    }
    if (max_len > max_len_row) {
      max_len_row = max_len;
      max_len_row_ind = i;
    }
  }
  // Выводим результаты
  printf("Количество столбцов, содержащих хотя бы один нулевой элемент: %d\n", count_zero);
  printf("Номер строки, в которой находится самая длинная серия одинаковых элементов: %d\n", max_len_row_ind);
  return 0;
}
