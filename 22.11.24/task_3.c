#include <stdio.h>

// ? 3.	Описать двумерный массив arr[2][3]. Создать на него указатель, проверить чему равна единица хранения. Ввести и распечатать его значения, используя указатель.

void print2DArrayWithPointer(int arr[2][3], int rows, int cols);

int main()
{
    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };

    printf("2D Array Elements:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    print2DArrayWithPointer(arr, 2, 3);

    return 0;
}


void print2DArrayWithPointer(int arr[2][3], int rows, int cols)
{
    int* ptr = &arr[0][0];
    printf("Using Pointer:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(ptr + i * cols + j));
        }

        printf("\n");
    }
}