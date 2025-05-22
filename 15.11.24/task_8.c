#include <stdio.h>

//  8.	В файле записана непустая последовательность целых чисел, являющихся числами Фибоначчи.
//      Приписать еще n чисел Фибоначчи. Число n ввести, предварительно выдав на печать уже имеющиеся в файле числа.

void writeFibonacciToFile(FILE *file, int n);

int main() {
    FILE *file = fopen("fibonacci.txt", "r+");
    if (!file)
    {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    printf("Существующие числа Фибоначчи в файле:\n");

    int num = 0;
    while (fscanf(file, "%d", &num) != EOF)
    {
        printf("%d ", num);
    }
    printf("\n");

    int n = 0;
    printf("Введите количество чисел Фибоначчи для добавления: ");
    scanf("%d", &n);

    fseek(file, 0, SEEK_END);

    writeFibonacciToFile(file, n);

    fclose(file);

    return 0;
}

void writeFibonacciToFile(FILE *file, int n)
{
    int a = 0;
    int b = 1;

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d ", a);

        int next = a + b;
                        a = b;
                            b = next;
    }

    return;
}
