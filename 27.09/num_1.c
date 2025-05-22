#include <stdio.h>
#include  <math.h>

// Затабулировать функцию sin(x+y), x лежит в интервале [a, b] и изменяется с шагом
// h, y изменяется от z с шагом h1. Вывести x, y, x+y и sin(x+y)


int main() {
    float  a = 0;
    float  b = 0;
    float  z = 0;
    float  h = 0;
    float h1 = 0;

    printf("Enter values a, b, z, h, h1:  \n");
    scanf("%f %f %f %f %f", &a, &b, &z, &h, &h1);

    float x;
    float y;

    for (x = a, y = z; x < b; x += h, y += h1) {
         printf("x = %f, y = %f, (x + y) = %f, sin(x + y) = %f", x, y, (x + y), sin(x + y));
    }
}

