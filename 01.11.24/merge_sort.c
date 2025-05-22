#include <stdio.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main()
{
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    mergeSort(arr1, n1);

    printf("Sorted array: \n");

    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
}


void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L_arr[n1] = {};
    int R_arr[n2] = {};

    for (int i = 0; i < n1; i++)
        L_arr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R_arr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L_arr[i] <= R_arr[j]) {
            arr[k++] = L_arr[i++];
        } else {
            arr[k++] = R_arr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L_arr[i++];
    }

    while (j < n2) {
        arr[k++] = R_arr[j++];
    }

    return;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    return;
}