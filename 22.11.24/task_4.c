#include <stdio.h>
#include <stdlib.h>

int** createArrayPointerMethod(int rows, int cols);
int* createArrayFlatMethod(int rows, int cols);

int main() {
    int rows = 3, cols = 4;

    // Первый способ
    int** arr1 = createArrayPointerMethod(rows, cols);
    fillAndPrintArrayPointerMethod(arr1, rows, cols);
    for (int i = 0; i < rows; i++) free(arr1[i]);
    free(arr1);

    // Второй способ
    int* arr2 = createArrayFlatMethod(rows, cols);
    fillAndPrintArrayFlatMethod(arr2, rows, cols);
    free(arr2);

    return 0;
}
// Первый способ: Массив указателей
int** createArrayPointerMethod(int rows, int cols)
{
    int** arr = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    return arr;
}

// Второй способ: Одномерный массив
int* createArrayFlatMethod(int rows, int cols)
{
    return (int*)malloc(rows * cols * sizeof(int));
}

void fillAndPrintArrayPointerMethod(int** arr, int rows, int cols)
{
    printf("Filling array (pointer method):\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = i * cols + j;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return;
}

void fillAndPrintArrayFlatMethod(int* arr, int rows, int cols)
{
    printf("Filling array (flat method):\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i * cols + j] = i * cols + j;
            printf("%d ", arr[i * cols + j]);
        }
        printf("\n");
    }

    return;
}

