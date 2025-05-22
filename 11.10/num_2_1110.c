#include <stdio.h>


void find_saddle_point(int matrix[10][10], int n, int m);


int main() {
    int matrix[10][10] = {{}};
    int n = 0;
    int m = 0;

    printf("Enter the number of columns and lines: ");
    scanf("%d %d", &n, &m);

    printf("Enter the matrix elements: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    find_saddle_point(matrix, n, m);

    return 0;
}

void find_saddle_point(int matrix[10][10], int n, int m) {
    int kSaddlePoint = -1;

    for (int i = 0; i < n; i++) {
        int kRowMin = matrix[i][0];
        int colIndex = 0;

        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] < kRowMin)
            {
                kRowMin = matrix[i][j];
                colIndex = j;
            }
        }
        int isMaxInCol = 1;
        for (int k = 0; k < n; k++)
        {
            if (matrix[k][colIndex] > kRowMin)
            {
                isMaxInCol = 0;
                break;
            }
        }
        if (isMaxInCol)
        {
            kSaddlePoint = kRowMin;
            printf("Saddle point was found: element '%d' in line %d in column %d\n", kSaddlePoint, i + 1, colIndex + 1);
            return;
        }
    }

    if (kSaddlePoint == -1)
    {
        printf("Saddle point wasn't found. \n");
    }

    return;
}
