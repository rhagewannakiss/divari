#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 10000
int main()
{
    unsigned long long N;
    int *count = (int *)calloc(MAX_NUM + 1, sizeof(int));
    if (count == NULL)
    {
        printf(" ERROR: cannot allocate memory. \n");
        return 1;
    }
    printf("Enter the number of elements N (0 <= N < 100000000): ");
    scanf("%llu", &N);
    if (N >= 100000000)
    {
        printf("ERROR: N should be lees than 100000000! \n");
        free(count);
        return 1;
    }
    printf("Enter %llu of real numbers (each should be not bigger than 10000!):\n", N);
    for (unsigned long long i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);

        if (num >= 1 && num <= MAX_NUM)
        {
            count[num] = 1;
        }
    }
    printf("Unique numbers:  \n");
    for (int i = 1; i <= MAX_NUM; i++)
    {
        if (count[i] == 1)
        {
            printf("%d\n", i);
        }
    }
    free(count);
    return 0;
}
