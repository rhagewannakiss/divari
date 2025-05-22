#include <stdio.h>
#include  <math.h>

// 9x1+2=11
// 9x12+3=111
// 9x123+4=1111
// 9x1234+5=11111….
//  Проверить утверждение для всех допустимых n, выдать результат на печать в цикле:

void checker_function();

int main()
{
    checker_function();
    return 0;
}

void checker_function()
{
    for (int i = 9; i > 0; i--) {
        long int a = 123456789;
        a = a / (int)pow(10, i);
        int b = a % 10;
        printf("9*%ld + %d = %ld\n", a, b + 1, 9 * a + b + 1);

    }

    return;
}