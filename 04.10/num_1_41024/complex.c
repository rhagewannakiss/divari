#include "complex.h"
#include <stdio.h>

Complex add(Complex a, Complex b)
{
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subtract(Complex a, Complex b)
{
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex multiply(Complex a, Complex b)
{
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex divide(Complex a, Complex b)
{
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;
    if (denominator == 0)
    {
        printf("ERROR: you can't divide by zero!\n");
        result.real = 0;
        result.imag = 0;
        return result;
    }
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}
