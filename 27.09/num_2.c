#include <stdio.h>
#include  <math.h>

//2. Дано десятичное целое число. Найти сумму всех цифр числа.

int main(){

    printf("Enter an int: ");
    int n = 0, sum = 0;
    scanf("%d", &n);

    while (n > 0){
        sum = sum + (n % 10);
        n = n / 10;
    }

    printf("Sum: %d", sum);

    return 0;
}