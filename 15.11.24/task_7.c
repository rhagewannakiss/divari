#include <stdio.h>
#include <stdlib.h>

//  7.	В файл записать 20 строк по 5 целых чисел. Перед записью в файл,
//      ввести ширину поля для вывода целых чисел, затем прочесть 2-й и 4-й столбцы,
//      записать их во второй файл и выдать на печать.
//      В третий файл записать те же столбцы, но используя fseek

#define ROWS 20
#define COLS 5

void writeNumbersToFile(const char *filename, int width);
void readAndWriteColumns(const char *inputFile, const char *outputFile1, const char *outputFile2);

int main()
{
    int width;
    printf("Введите ширину поля для вывода целых чисел: ");
    scanf("%d", &width);

    const char *inputFile = "numbers.txt";
    const char *outputFile1 = "columns.txt";
    const char *outputFile2 = "columns_fseek.txt";

    // Запись чисел в файл
    writeNumbersToFile(inputFile, width);

    // Чтение и запись столбцов
    readAndWriteColumns(inputFile, outputFile1, outputFile2);

    return 0;
}

void writeNumbersToFile(const char *filename, int width)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Ошибка открытия файла для записи!\n");
        return;
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fprintf(file, "%*d ", width, rand() % 100);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    return;
}

void readAndWriteColumns(const char *inputFile, const char *outputFile1, const char *outputFile2)
{
    FILE *file = fopen(inputFile, "r");
    if (!file) {
        printf("Ошибка открытия входного файла!\n");
        return;
    }

    FILE *file1 = fopen(outputFile1, "w");
    if (!file1)
    {
        printf("Ошибка открытия выходного файла 1!\n");
        fclose(file);
        return;
    }

    int secondColumn[ROWS], fourthColumn[ROWS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int num;
            fscanf(file, "%d", &num);

            if (j == 1)
            {
                secondColumn[i] = num;
            }
            if (j == 3)
            {
                fourthColumn[i] = num;
            }
        }
    }

    printf("2-й и 4-й столбцы:\n");
    for (int i = 0; i < ROWS; i++)
    {
        fprintf(file1, "%d %d\n", secondColumn[i], fourthColumn[i]);
        printf("%d %d\n", secondColumn[i], fourthColumn[i]);
    }

    fclose(file1);
    fclose(file);

    file1 = fopen(outputFile2, "w");
    if (!file1)
    {
        printf("Ошибка открытия выходного файла 2!\n");
        return;
    }

    for (int i = 0; i < ROWS; i++)
    {
        fprintf(file1, "%d %d\n", secondColumn[i], fourthColumn[i]);
    }

    fclose(file1);

    return;
}