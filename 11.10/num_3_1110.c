#include <stdio.h>

void printMatrix(int matrix[10][10], int n);
void transposeMatrix(int matrix[10][10], int n);


int main() {
    int n;
    int matrix[10][10];

    printf("Enter the order of a square matrix (n <= 10): ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Source matrix:\n");
    printMatrix(matrix, n);

    transposeMatrix(matrix, n);

    printf("Transposed matrix: \n");
    printMatrix(matrix, n);

    return 0;
}

void printMatrix(int matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

void transposeMatrix(int matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    return;
}