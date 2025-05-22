#include <stdio.h>
#include <stdlib.h>

int main() {
    int numFiles = 0;

    printf("Введите количество файлов для объединения: ");
    scanf("%d", &numFiles);

    char outputFileName[100] = {};

    printf("Введите имя выходного файла: ");
    scanf("%s", outputFileName);

    FILE *outputFile = fopen(outputFileName, "w");
    if (!outputFile)
    {
        printf("Ошибка открытия выходного файла!\n");
        return 1;
    }

    for (int i = 0; i < numFiles; i++)
    {
        char inputFileName[100] = {};

        printf("Введите имя файла %d: ", i + 1);
        scanf("%s", inputFileName);

        FILE *inputFile = fopen(inputFileName, "r");
        if (!inputFile)
        {
            printf("Ошибка открытия файла %s!\n", inputFileName);
            continue;
        }

        char ch = '\0';

        while ((ch = fgetc(inputFile)) != EOF)
        {
            fputc(ch, outputFile);
        }

        fclose(inputFile);
    }

    fclose(outputFile);

    printf("Файлы успешно объединены в %s\n", outputFileName);

    return 0;
}