#include <stdio.h>

//3.	Дана дата;
//      char dd = 29, mm = 10, yy = 24
//      запаковать ее в 2 байта в том же порядке dd – mm – yy.


int main() {
    char dd = 29;
    char mm = 10;
    char yy = 24;

    unsigned short PackedDate = (dd << 9) | (mm << 5) | yy;

    printf("Упакованная дата: 0x%04X\n", PackedDate);
    return 0;
}