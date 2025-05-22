#include <stdio.h>
#include  <math.h>

// Ввести два натуральных числа и используя алгоритм Эвклида найти НОД.

int NOD_func(int a, int b);

int main()
{
    printf("Enter values a, b:  \n");
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);

    printf("NOD = %d \n", NOD_func(a, b));

    return 0;
}


int NOD_func(int a, int b)
{
    int t = 0;

    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }

    return a;
}