#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int **arr, int size) {
    *arr = (int *)malloc(size * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        (*arr)[i] = rand() % 100; // Заполняем случайными числами от 0 до 99
    }
}

void removeEven(int **arr, int *size) {
    int oddCount = 0;

    for (int i = 0; i < *size; ++i) {
        if ((*arr)[i] % 2 != 0) {
            (*arr)[oddCount++] = (*arr)[i];
        }
    }
    *size = oddCount;

}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int *array;
    int size;

    printf("Введите размер массива: ");
    scanf("%d", &size);

    fillArray(&array, size);
    printf("Исходный массив:\n");
    printArray(array, size);


    removeEven(&array, &size);


    printf("Массив после удаления четных элементов:\n");
    printArray(array, size);

    free(array);

    return 0;
}