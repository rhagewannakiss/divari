#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of elements in the array (n > 0): ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("ERROR: number of elements in the array should be bigger than 0! \n");
        return 1;
    }
    int a[n];
    printf("Enter %d of real numbers: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int is_in_the_right_order = 1;
    int mistakes = 0;
    long long p = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] >= a[i + 1])
        {
            is_in_the_right_order = 0;
            mistakes++;
        }
        else
        {
            p *= (a[i + 1] - a[i]);
        }
    }
    if (is_in_the_right_order)
    {
        printf("Elements are in the right order. THe value of p: %lld\n", p);
    }
    else
    {
        printf("Elemenets are not in the right order. Number of violations: %d\n", mistakes);
    }
    return 0;
}
