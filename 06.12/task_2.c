#include <stdio.h>
#include <stdlib.h>

//2.	Напишите программу, которая принимает аргументы – три целых числа и выводит на печать их сумму.

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Wrong amount of arguments. Please use the program like this: %s <num1> <num2> <num3>\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int num3 = atoi(argv[3]);

    int sum = num1 + num2 + num3;

    printf("The sum of %d, %d, and %d: sum = %d.\n", num1, num2, num3, sum);

    return 0;
}

