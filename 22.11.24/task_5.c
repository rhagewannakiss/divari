#include <stdio.h>
#include <stdlib.h>

void allocateAndPrintFixed(float (*matr)[10], int rows, int cols) {
    printf("Values and addresses (matr):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matr[i][j] = i + j + 0.1f;
            printf("Value: %.1f, Address: %p\n", matr[i][j], (void*)&matr[i][j]);
        }
    }
}

int main() {
    int rows = 3, cols = 4;
    float matr[10][10];
    allocateAndPrintFixed(matr, rows, cols);
    return 0;
}


//!или

#include <stdio.h>
#include <stdlib.h>

void allocateAndPrintDynamic(float*** matr, int rows, int cols) {
    *matr = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        (*matr)[i] = (float*)malloc(cols * sizeof(float));
    }

    printf("Values and addresses (dynamic matr):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            (*matr)[i][j] = i + j + 0.1f;
            printf("Value: %.1f, Address: %p\n", (*matr)[i][j], (void*)&(*matr)[i][j]);
        }
    }
}

int main() {
    int rows = 3, cols = 4;
    float** matr;

    allocateAndPrintDynamic(&matr, rows, cols);

    // Освобождение памяти
    for (int i = 0; i < rows; i++) free(matr[i]);
    free(matr);

    return 0;
}
