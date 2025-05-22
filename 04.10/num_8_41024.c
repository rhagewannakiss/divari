#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGITS 1000
typedef struct {
    int digits[MAX_DIGITS];
    int size;
} BigInt;
void print_BigInt(BigInt num);
BigInt factorial(int n);
void init_BigInt(BigInt *num);
void multiply(BigInt *result, int multiplier);

int main()
{
    int n;
    printf("Enter the number n for factorial calculation (0 < n < 1000): ");
    scanf("%d", &n);
    if (n < 0
     || n >= 1000)
    {
        printf("ERROR: n should be more than 0 and lees than 1000.\n");
        return 1;
    }
    BigInt result = factorial(n);
    printf("Factorial %d = ", n);
    printBigInt(result);
    return 0;
}

void init_BigInt(BigInt *num)
{
    for (int i = 0; i < MAX_DIGITS; i++)
    {
        num->digits[i] = 0;
    }
    num->size = 1;
    return;
}
void multiply(BigInt *result, int multiplier)
{
    int carry = 0;
    for (int i = 0; i < result->size; i++)
    {
        int prod = result->digits[i] * multiplier + carry;
        result->digits[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry > 0)
    {
        result->digits[result->size] = carry % 10;
        carry /= 10;
        result->size++;
    }
    return;
}
BigInt factorial(int n)
{
    BigInt result;
    initBigInt(&result);
    result.digits[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        multiply(&result, i);
    }
    return result;
}
void print_BigInt(BigInt num)
{
    for (int i = num.size - 1; i >= 0; i--)
    {
        printf("%d", num.digits[i]);
    }
    printf("\n");
    return;
}