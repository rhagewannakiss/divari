#include <stdio.h>
#include <stdlib.h>


void findAndAppendMaxSubarray(int** arr, int* n, int m);

int main()
{
    int n = 6, m = 3;
    int* arr = (int*)malloc(n * sizeof(int));
    arr[0] = 1; arr[1] = -2; arr[2] = 3; arr[3] = 10; arr[4] = -4; arr[5] = 7;

    printf("Original Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    findAndAppendMaxSubarray(&arr, &n, m);

    printf("Updated Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

void findAndAppendMaxSubarray(int** arr, int* n, int m)
{
    int maxSum = -99999999;
    int startIndex = 0;

    for (int i = 0; i <= *n - m; i++)
    {
        int currentSum = 0;

        for (int j = 0; j < m; j++)
        {
            currentSum += (*arr)[i + j];
        }
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            startIndex = i;
        }
    }

    *arr = (int*)realloc(*arr, (*n + m) * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        (*arr)[*n + i] = (*arr)[startIndex + i];
    }

    *n += m;
}