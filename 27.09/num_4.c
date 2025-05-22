
#include  <stdio.h>
#include <stdlib.h>
#include   <math.h>

// Вычислить значения функции sin, проверить, используя функции библиотеки math.
// Обязательно использовать рекуррентную формулу.

double sin_function(double x);

int main()
{
    printf("Enter x: \n");
    double x = 0;
    scanf("%lf", &x);

    printf("Function sin output = %lf\n", sin(x));
    printf("My sin function output = %lf\n", sin_function(x));

    return 0;
}


double sin_function(double x)
{
    double   n = x;
    double sum = 0;
    int      i = 1;

    do {
        sum += n;
        n *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
        i++;
    }
    while (fabs(n) > 1e-5);

    return sum;
}