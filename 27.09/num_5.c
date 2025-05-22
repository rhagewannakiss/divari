#include   <stdio.h>
#include <stdbool.h>

//Решить квадратное уравнение методом деления отрезка пополам

int square_solver(int a, int b, int c, int l, int r);

int main() {
    int a = 1;
    int b = -4;
    int c = 4;

    int x1 = 2;
    int x2 = 2;

    int g1 = 0;
    int h1 = 4;
    int g2 = 1;
    int h2 = 3;

    printf("Expected: %d,\t Our function output: %d\n", x1, square_solver(a, b, c, g1, h1));
    printf("Expected: %d,\t Our function output: %d\n", x2, square_solver(a, b, c, g2, h2));

    return 0;
}

int square_solver(int a, int b, int c, int l, int r) {
    int middle = 0;

    if ((a * l * l + b * l + c * c > 0) && (a * r * r + b * r + c > 0)) {
        return -1;
    }

    while (l <= r) {
        middle = (l + r) / 2;
        int f_mid = a * middle * middle + b * middle + c;

        if (f_mid == 0) {
            return middle;
        }

        if ((a * l * l + b * l + c) * f_mid < 0) {
            r = middle - 1;
        }

        else {
            l = middle + 1;
        }
    }

    return -1;
}
