#include <stdio.h>
#include  <math.h>

// Используя метод полного перебора решить уравнения

void equation_solver(int k0, int k1, int k2, int k3, int k4);

int main(){

    printf("Sollution to 1st equation:  \n");
    equation_solver(1, -1, 2, -5, -57);

    printf("Sollution to 2nd equation:  \n");
    equation_solver(2, -3, 2, -5, -84);

    printf("Sollution to 3rd equation:  \n");
    equation_solver(1, -3, 2, -5,  -3);
}

void equation_solver(int k0, int k1, int k2, int k3, int k4){
    for (double i = -1000; i < 1000; i = i + 0.01) {

        if (fabs(k4*pow(i, 4) + k3*pow(i, 3) + k2*(i, 2) + k1*i + k0) < 0.2)
           printf("%g ", i);

    }
    printf("\n");
}