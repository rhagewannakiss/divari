#include "complex.h"
#include <stdio.h>

void printComplex(Complex c);

int main()
{
    Complex a = {4, 5};
    Complex b = {1, 2};

    Complex sum = add(a, b);
    Complex diff = subtract(a, b);
    Complex prod = multiply(a, b);
    Complex quot = divide(a, b);

    printf("Sum of complex numbers a and b: ");
    printComplex(sum);

    printf("Difference of complex numbers a and b: ");
    printComplex(diff);

    printf("Product of complex numbers a and b: ");
    printComplex(prod);

    printf("Quotient of complex numbers a and b: ");
    printComplex(quot);

    return 0;
}


void printComplex(Complex c)
{
    if (c.imag >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.imag);
    }

    return;
}
