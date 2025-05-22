#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//     4.	*Решето Эратосфена. Вывести простые числа до 1000. Для хранения информации о простом или составном числе использовать массив типа char ( 1 байт ).

#define MAX 1000

int main()
{
    char *array = (char*)calloc(MAX / 8 + 1, sizeof(char));
    if (!array)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    for (int i = 2; i * i < MAX; i++)
    {
        if (!(array[i / 8] & (1 << (i % 8))))
        {
            for (int j = i * i; j < MAX; j += i)
            {
                array[j / 8] |= (1 << (j % 8));
            }
        }
    }

    printf("Простые числа до 1000:\n");
    for (int i = 2; i < MAX; i++)
    {
        if (!(array[i / 8] & (1 << (i % 8))))
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(array);

    return 0;
}