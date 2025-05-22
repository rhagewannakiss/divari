#include <stdio.h>

void multiplyMatrices(int firstMatrix[10][10], int secondMatrix[10][10], int resultMatrix[10][10], int row1, int col1, int row2, int col2);

int main() {
    int firstMatrix[10][10], secondMatrix[10][10], resultMatrix[10][10];
    int row1, col1, row2, col2;

    printf("Enter the number of rows and columns of the first matrix: \n ");
    scanf("%d %d", &row1, &col1);

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the first matrix: \n");
    scanf("%d %d", &row2, &col2);

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, row1, col1, row2, col2);

    return 0;
}

void multiplyMatrices(int firstMatrix[10][10], int secondMatrix[10][10], int resultMatrix[10][10], int row1, int col1, int row2, int col2) {
    if (col1 != row2) {
        printf("Multiplication is not possible. The number of columns of the first matrix must be equal to the number of rows of the second matrix.\n");
        return;
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            resultMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }

    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%4d ", resultMatrix[i][j]);
        }
        printf("\n");
    }
    return;
}

