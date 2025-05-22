#include <stdio.h>
#include  <math.h>

// Теорема Лагранжа о четырех квадратах утверждает, что каждое натуральное число
// можно записать как сумму квадратов четырех неотрицательных целых чисел,
// включая ноль. Представить введенное натуральное число как сумму квадратов
// четырех неотрицательных чисел.

int lagrange(int number);

int main() {
    printf("Enter value a:  \n");
    int a = 0;
    scanf("%d", &a);

    lagrange(a);
}

int lagrange(int number)
{
    double d = 0;

    for (int a = 0; a < (int)(sqrt(number) + 1); a++) {
        for (int b = 0; b < (int)(sqrt(number - a*a) + 1); b++) {
            for (int c = 0; c < (int)(sqrt(number - a*a - b*b) + 1); c++) {

                d = sqrt(number - a*a - b*b - c*c);

                if ((d - (int)d) < 0.001) {
                    printf("%d %d %d %d\n", a, b, c, (int)d);
                    return 0;
                }
            }
        }
    }
}