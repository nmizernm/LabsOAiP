#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void findLongestSequence(int *arr, int size) {
    int max_length = 0;
    int current_length = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
            }
            current_length = 0;
        }
    }

    if (current_length > max_length) {
        max_length = current_length;
    }

    printf("Максимальная длина последовательности положительных чисел: %d\n", max_length);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int rows, cols;
    printf("Введите количество строк и столбцов: ");
    scanf("%d %d", &rows, &cols);

    // Выделение памяти под двумерный массив
    int **arr2d = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr2d[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr2d[i][j]);
        }
    }

    // Преобразование двумерного массива в одномерный
    int *arr1d = (int *)malloc(rows * cols * sizeof(int));
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr1d[index++] = arr2d[i][j];
        }
    }

    findLongestSequence(arr1d, rows * cols);

    // Освобождение выделенной памяти
    for (int i = 0; i < rows; i++) {
        free(arr2d[i]);
    }
    free(arr2d);
    free(arr1d);

    return 0;
}