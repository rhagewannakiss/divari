#include <stdio.h>

//1.	Вывести двоичное представление целого числа типа int на экран без незначащий нулей.

typedef unsigned char byte;
void printBinNum();

int main() {
    printBinNum();
    return 0;
}


void printBinNum() {
    printf("Введите число: \n");
    byte b = 0;
    scanf("%s", &b);

    printf("Ваше число в двоичном представлении: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%c", (b & 0x80) ? '1' : '0');
        b <<= 1;
    }

    printf("\n");

    return;
}