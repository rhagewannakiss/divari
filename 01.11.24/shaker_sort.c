#include <stdio.h>

void shakerSort(int array[], int n);

int main()
{
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    shakerSort(arr1, n1);

    printf("Sorted array: \n");

    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
}

void shakerSort(int array[], int n)
{
    int left = 0;
    int right = n - 1;
    int last_swap = 0;

    while (left < right)
    {
        lastSwap = 0;

        for (int i = left; i < right; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1], sizeof(int));
                lastSwap = i;
            }
        }
        right = lastSwap;

        for (int i = right; i > left; i--)
        {
            if (array[i] < array[i - 1])
            {
                swap(&arr[i], &array[i - 1], sizeof(int));
                lastSwap = i;
            }
        }
        left = lastSwap;

    }
}