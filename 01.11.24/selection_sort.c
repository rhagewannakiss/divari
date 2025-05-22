#include <stdio.h>

void selectionSort(int arr[], int n);

int main()
{
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    selectionSort(arr1, n1);

    printf("Sorted array (Insertion Sort): \n");

    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(&arr[i], &arr[min_index], sizeof(int));
        }
    }

    return;
}