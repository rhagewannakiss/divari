#include <stdio.h>

// Используя структуру вложенных циклов вывести на экран
//  F
//  FE
//  FED
//  FEDC
//  FEDCB
//  FEDCBA

int main() {
    char ch;

    for (ch = 'F'; ch >= 'A'; ch--) {
        for (char c = 'F'; c >= ch; c--) {
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}

