#include <stdio.h>
#include  <math.h>

// Ввести два натуральных числа и методом полного перебора найти НОД.

void NOD_func(int a, int b);

int main()
{
    printf("Enter values a, b:  \n");
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);

    NOD_func(a, b);
}

void NOD_func(int a, int b)
{
    int i = 0;

    if (a > b){
        i = a;
    } else
        i = b;

    while (i > 0) {
        if (a % i == 0 && b % i == 0){
            printf("%d\n", i);
            break;
        }
        i--;
    }
}
