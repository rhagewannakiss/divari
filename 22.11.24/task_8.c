#include <stdio.h>
#include <stdlib.h>

// Проверка условий
int allElementsZero(int* row, int cols) {
    for (int j = 0; j < cols; j++) {
        if (row[j] != 0) return 0;
    }
    return 1;
}

int allElementsEqual(int* row, int cols) {
    for (int j = 1; j < cols; j++) {
        if (row[j] != row[0]) return 0;
    }
    return 1;
}

int allElementsEven(int* row, int cols) {
    for (int j = 0; j < cols; j++) {
        if (row[j] % 2 != 0) return 0;
    }
    return 1;
}

int isMonotonic(int* row, int cols) {
    int increasing = 1, decreasing = 1;
    for (int j = 1; j < cols; j++) {
        if (row[j] < row[j - 1]) increasing = 0;
        if (row[j] > row[j - 1]) decreasing = 0;
    }
    return increasing || decreasing;
}

int isPalindrome(int* row, int cols) {
    for (int j = 0; j < cols / 2; j++) {
        if (row[j] != row[cols - 1 - j]) return 0;
    }
    return 1;
}

// Формируем матрицу b
int** createConditionMatrix(int** matrix, int rows, int cols) {
    int** conditionMatrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        conditionMatrix[i] = (int*)malloc(5 * sizeof(int));
        conditionMatrix[i][0] = allElementsZero(matrix[i], cols);
        conditionMatrix[i][1] = allElementsEqual(matrix[i], cols);
        conditionMatrix[i][2] = allElementsEven(matrix[i], cols);
        conditionMatrix[i][3] = isMonotonic(matrix[i], cols);
        conditionMatrix[i][4] = isPalindrome(matrix[i], cols);
    }
    return conditionMatrix;
}

int main() {
    int rows = 4, cols = 5;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i == 0) ? 0 : (i + j) % 3 + 1; // Пример данных
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int** conditionMatrix = createConditionMatrix(matrix, rows, cols);

    printf("\nCondition Matrix (b):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", conditionMatrix[i][j]);
        }
        printf("\n");
        free(conditionMatrix[i]);
    }
    free(conditionMatrix);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
