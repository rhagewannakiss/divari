#include <stdio.h>

void bubbleSort(int arr[], int n);

int main()
{
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    bubbleSort(arr1, n1);

    printf("Sorted array: \n");

    for (int i = 0; i < n1; i++)
    {
        printf("%d ", arr1[i]);
    }
}


void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1], sizeof(int));
            }
        }
    }
}