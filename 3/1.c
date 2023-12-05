#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    double array[100];

    
    printf("Введите количество элементов массива (не более %d): ", 100);
    scanf("%d", &n);
    
    if (n < 1 || n > 100) {
        printf("Некорректное количество элементов.\n");
        return 0;
    }

    int choice;
    printf("Выберите способ инициализации массива:\n");
    printf("1. Ввести элементы вручную\n");
    printf("2. Заполнить случайными значениями\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Введите %d элементов массива:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &array[i]);
        }
    } else if (choice == 2) {
        
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            array[i] = (double)rand() / RAND_MAX * 100.0; 
        }
    } else {
        printf("Некорректный выбор.\n");
        return 0;
    }

    double sum_odd = 0.0, sum_between_negatives = 0.0 ;
    int first_negative = -1;
    int last_negative = -1;
    for (int i = 1; i < n; i += 2) {
        sum_odd += array[i];
    }

    for (int i = 0; i < n; i++) {
        if (array[i] < 0) {
            if (first_negative == -1) {
                first_negative = i;
            }
            last_negative = i;
        }
    }
    if (first_negative != -1 && last_negative != -1) {
        for (int i = first_negative + 1; i < last_negative; i++) {
            sum_between_negatives += array[i];
        }
    }

    printf("Сумма элементов с нечетными номерами: %d\n", (int)sum_odd);
    if (first_negative != -1 && last_negative != -1) {
        printf("Сумма элементов между первым и последним отрицательными элементами: %d\n", (int)sum_between_negatives);
    } else {
        printf("В массиве нет отрицательных элементов.\n");
    }

    return 0;
}
