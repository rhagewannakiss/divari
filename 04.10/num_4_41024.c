#include <stdio.h>
int main()
{
    int n;
    printf("enter numbers of elements in the array (n > 0):  ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("ERROR: number of elements in the array should be more than 0. \n");
        return 1;
    }
    int a[n];
    printf("Enter elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int max_length = 1;
    int current_length = 1;
    int common_difference = 0;
    for (int i = 1; i < n; i++)
    {
        if (i == 1)
        {
            common_difference = a[i] - a[i - 1];
        }
        if (a[i] - a[i - 1] == common_difference)
        {
            current_length++;
        }
        else
        {
            if (current_length > max_length)
            {
                max_length = current_length;
            }
            current_length = 2;
            common_difference = a[i] - a[i - 1];
        }
    }
    if (current_length > max_length)
    {
        max_length = current_length;
    }
    printf("length of the longest array: %d\n", max_length);
    return 0;
}
