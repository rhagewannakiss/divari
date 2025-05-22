#include <stdio.h>
#include <stdlib.h>


// *10. Дан текстовый файл, содержащий вещественные числа. Найти максимум и минимум, поменять их в файле местами.
//      Для решения задачи не использовать массив. Обмен данными произвести прямо в файле.
//      Для этого необходимо предварительно записать данные в файл по определенному формату.

void swapNumbersInFile(const char *filename);

int main()
{
    const char *filename = "numbers.txt"; // Укажите имя файла с вещественными числами
    swapNumbersInFile(filename);

    return 0;
}

void swapNumbersInFile(const char *filename)
{
    FILE *file = fopen(filename, "r+");

    if (!file)
    {
        printf("Ошибка открытия файла!\n");
        return;
    }

    float min = 0;
    float max = 0;
    long minPos = -1;
    long maxPos = -1;
    float num = 0;
    int first = 1;

    while (fscanf(file, "%f", &num) != EOF)
    {
        if (first)
        {
            min = max = num;
            minPos = ftell(file) - sizeof(num);
            maxPos = ftell(file) - sizeof(num);
            first = 0;
        }
        else
        {
            if (num < min)
            {
                min = num;
                minPos = ftell(file) - sizeof(num);
            }
            if (num > max)
            {
                max = num;
                maxPos = ftell(file) - sizeof(num);
            }
        }
    }

    if (minPos != -1 && maxPos != -1)
    {
        fseek(file, minPos, SEEK_SET);
        fwrite(&max, sizeof(max), 1, file);

        fseek(file, maxPos, SEEK_SET);
        fwrite(&min, sizeof(min), 1, file);
    }

    fclose(file);
    printf("Минимум и максимум успешно поменяны местами.\n");
}
