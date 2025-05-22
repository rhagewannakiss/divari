#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct Complex {
    double real;
    double imag;
} Complex;

Complex add(Complex a, Complex b);
Complex subtract(Complex a, Complex b);
Complex multiply(Complex a, Complex b);
Complex divide(Complex a, Complex b);

#endif // COMPLEX_H
