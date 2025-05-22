#include <stdio.h>
#include <stdlib.h>

//   6.	Посимвольно прочесть символы из файла (до конца файла), записать в строку и распечатать как строку. Для работы со строкой использовать указатели.

void readCharactersFromFile() ;

int main()
{
    readCharactersFromFile();
    return 0;
}

void readCharactersFromFile() {
    FILE *file = fopen("input.txt", "r");
    if (!file)
    {
        printf("Ошибка открытия файла!\n");
        return;
    }

    char *str = (char*)malloc(100 * sizeof(char));
    int i = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        str[i++] = ch;
    }
    str[i] = '\0';

    printf("Содержимое файла: %s\n", str);
    free(str);
    fclose(file);

    return;
}
