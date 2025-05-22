#include <stdio.h>

//Найти минимальный элемент одномерного массива, используя рекурсию.

int FindMinRecursive(int arr[], int size);

int main()
{
    int arr[] = {5, 3, 8, 1, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("The minimum element is: %d\n", FindMinRecursive(arr, size));

    return 0;
}

int FindMinRecursive(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int MeowMin = FindMinRecursive(arr + 1, size - 1);

    return arr[0] < MeowMin ? arr[0] : MeowMin;
}