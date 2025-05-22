#include <stdio.h>
#include <stdlib.h>

//1.	Напишите программу, которая принимает аргумент -- имя файла, и выводит содержимое этого файла.

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        if (argc > 2)
        {
            fprintf(stderr, "Too much files given. Should be one. Please use the program like this: %s <file_name>\n", argv[0]);
        }
        if (argc < 2)
        {
            fprintf(stderr, "Wasn't given enough files. Should be one. Please use the program like this: %s <file_name>\n", argv[0]);
        }

        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char ch;

    do
    {
        ch = fgetc(file);

        if (ch != EOF)
        {
            putchar(ch);
        }
    } while (ch != EOF);

    fclose(file);

    return 0;
}
