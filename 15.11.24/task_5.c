#include <stdio.h>

void inputAndOutputArray();

int main() {
    inputAndOutputArray();
    return 0;
}

void inputAndOutputArray() {
    int arr[10];
    FILE *file;

    // Ввод массива
    printf("Введите 10 чисел:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Перенаправление вывода в файл
    file = fopen("output.txt", "w");
    for (int i = 0; i < 10; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);

    // Чтение из файла
    file = fopen("output.txt", "r");
    printf("Числа из файла:\n");
    for (int i = 0; i < 10; i++)
    {
        fscanf(file, "%d", &arr[i]);
        printf("%d ", arr[i]);
    }

    fclose(file);
    printf("\n");
}
