#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void deleteRowWithMinSum(int ***array, int *rows) {
    int minSum = __INT_MAX__;
    int minRowIndex = -1;

    // Находим строку с минимальной суммой элементов
    for (int i = 0; i < *rows; i++) {
        int currentSum = 0;
        int *currentRow = (*array)[i];

        while (*currentRow != 0) {
            currentSum += *currentRow;
            currentRow++;
        }

        if (currentSum < minSum) {
            minSum = currentSum;
            minRowIndex = i;
        }
    }

    // Удаляем строку с минимальной суммой элементов
    if (minRowIndex != -1) {
        free((*array)[minRowIndex]); // Освобождаем память строки

        // Сдвигаем указатели на строки
        for (int i = minRowIndex; i < *rows - 1; i++) {
            (*array)[i] = (*array)[i + 1];
        }
        (*array) = realloc((*array), (*rows - 1) * sizeof(int *)); // Уменьшаем размер массива строк
        (*rows)--;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int rows;
    printf("Введите количество строк в массиве: ");
    scanf("%d", &rows);

    int **array = (int **)malloc(rows * sizeof(int *));
    if (array == NULL) {
        printf("Ошибка выделения памяти.\n");
        return -1;
    }

    // Ввод двумерного массива
    for (int i = 0; i < rows; i++) {
        printf("Введите элементы строки %d (0 для завершения): ", i + 1);
        int *row = NULL;
        int value, count = 0;

        while (1) {
            scanf("%d", &value);
            if (value == 0) {
                break;
            }

            count++;
            int *temp = (int *)realloc(row, count * sizeof(int));
            if (temp != NULL) {
                row = temp;
            } else {
                printf("Ошибка выделения памяти.\n");
                exit(EXIT_FAILURE);
            }

            row[count - 1] = value;
        }

        row = (int *)realloc(row, (count + 1) * sizeof(int)); // Добавляем место для завершающего нуля
        row[count] = 0; // Добавляем завершающий ноль

        array[i] = row;
    }

    deleteRowWithMinSum(&array, &rows);

    // Вывод оставшегося массива
    printf("Оставшийся массив:\n");
    for (int i = 0; i < rows; i++) {
        int *currentRow = array[i];
        while (*currentRow != 0) {
            printf("%d ", *currentRow);
            currentRow++;
        }
        printf("0\n");
    }

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}