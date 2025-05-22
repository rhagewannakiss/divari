#include <stdio.h>
#include <stdlib.h>

// Проверяет, содержит ли строка отрицательные элементы
int hasNoNegativeElements(int* row, int cols) {
    for (int j = 0; j < cols; j++) {
        if (row[j] < 0) return 0;
    }
    return 1;
}

// Создает вторую матрицу из строк без отрицательных элементов
int** createMatrixWithoutNegatives(int** matrix, int rows, int cols, int* newRows) {
    int** result = NULL;
    *newRows = 0;

    for (int i = 0; i < rows; i++) {
        if (hasNoNegativeElements(matrix[i], cols)) {
            result = (int**)realloc(result, (*newRows + 1) * sizeof(int*));
            result[*newRows] = (int*)malloc(cols * sizeof(int));
            for (int j = 0; j < cols; j++) {
                result[*newRows][j] = matrix[i][j];
            }
            (*newRows)++;
        }
    }

    return result;
}

int main() {
    int rows = 4, cols = 5;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i % 2 == 0) ? i + j : i - j; // Пример данных
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int newRows;
    int** filteredMatrix = createMatrixWithoutNegatives(matrix, rows, cols, &newRows);

    printf("\nFiltered Matrix:\n");
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", filteredMatrix[i][j]);
        }
        printf("\n");
        free(filteredMatrix[i]);
    }
    free(filteredMatrix);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
