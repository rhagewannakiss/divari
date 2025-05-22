#include <stdio.h>
void rearrange(int arr[], int n);
int main()
{
    int n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements fo the array :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    rearrange(arr, n);
    printf("Array after rearrange :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
void rearrange(int arr[], int n)
{
    int positive_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            if (i != positive_index)
            {
                int temp = arr[i];
                arr[i] = arr[positive_index];
                arr[positive_index] = temp;
            }
            positive_index++;
        }
    }
    return;
}