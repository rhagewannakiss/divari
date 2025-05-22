#include <stdio.h>
#include <stdlib.h>

// Вычисление скалярного произведения двух строк
int scalarProduct(int* row1, int* row2, int cols) {
    int product = 0;
    for (int i = 0; i < cols; i++) {
        product += row1[i] * row2[i];
    }
    return product;
}

// Чтение массива из файла
int** readMatrixFromFile(const char* filename, int* rows, int* cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    fscanf(file, "%d %d", rows, cols);
    int** matrix = (int**)malloc(*rows * sizeof(int*));
    for (int i = 0; i < *rows; i++) {
        matrix[i] = (int*)malloc(*cols * sizeof(int));
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);
    return matrix;
}

void findMaxMinDistanceRows(int** matrix, int rows, int cols) {
    int maxDistance = -1, minDistance = __INT_MAX__;
    int rowMax1, rowMax2, rowMin1, rowMin2;

    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < rows; j++) {
            int distance = scalarProduct(matrix[i], matrix[j], cols);
            if (distance > maxDistance) {
                maxDistance = distance;
                rowMax1 = i;
                rowMax2 = j;
            }
            if (distance < minDistance) {
                minDistance = distance;
                rowMin1 = i;
                rowMin2 = j;
            }
        }
    }

    printf("Max Distance: %d (Rows %d and %d)\n", maxDistance, rowMax1, rowMax2);
    printf("Min Distance: %d (Rows %d and %d)\n", minDistance, rowMin1, rowMin2);
}

int main() {
    int rows, cols;
    int** matrix = readMatrixFromFile("matrix.txt", &rows, &cols);

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    findMaxMinDistanceRows(matrix, rows, cols);

    // Освобождение памяти
    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);

    return 0;
}
