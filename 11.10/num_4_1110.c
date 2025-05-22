#include <stdio.h>

void generateMagicSquare(int n);

int main() {
    int n;
    do
    {
        printf("Enter a size of a magic square (> 0): ");
        scanf("%d", &n);
    }
    while (n <= 0
        || n % 2 == 0);
    generateMagicSquare(n);

    return 0;
}

void generateMagicSquare(int n) {
    int magicSquare[15][15] = {{}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            magicSquare[i][j] = 0;
        }
    }

    int i = 0;
    int j = n / 2;

    for (int num = 1; num <= n * n; num++)
    {
        magicSquare[i][j] = num;
        int newI = (i - 1 + n) % n;
        int newJ = (j + 1) % n;

        if (magicSquare[newI][newJ] != 0)
        {
            i = (i + 1) % n;
        }
        else
        {
            i = newI;
            j = newJ;
        }
        return;
    }

    printf("A magic square of size %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", magicSquare[i][j]);
        }
        printf("\n");
    }
    int magicConstant = n * (n * n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += magicSquare[i][j];
        }
        if (sum != magicConstant)
        {
            printf("Error: Strings are not equal to magic constant!\n");
            return;
        }
    }

    for (int j = 0; j < n; j++)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += magicSquare[i][j];
        }
        if (sum != magicConstant)
        {
            printf("Error: Columns are not equal to the magic constant! \n");
            return;
        }
    }

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += magicSquare[i][i];
    }
    if (sum != magicConstant)
    {
        printf("Error: main diagonal is not equal to the magic constant!\n");
        return;
    }

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += magicSquare[i][n - i - 1];
    }
    if (sum != magicConstant)
    {
        printf("Error: secondary diagonal is not equal to the magic constant!\n");
        return;
    }

    printf("The matrix is ​​really a magic square with a magic constant: %d\n", magicConstant);
}
