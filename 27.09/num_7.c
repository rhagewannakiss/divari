#include <stdio.h>

// Водить числа до окончания ввода, найти:
// ∑ положительных элементов и их количество. и их кол-во.
// Количество вводимых чисел неизвестно. Прервать ввод в любом месте.

int main() {
    int num;
    int sum = 0;
    int count = 0;

    printf("Enter numbers (press Ctrl+D to finish input): \n");

    while (scanf("%d", &num) == 1) {

        if (num > 0) {
            sum += num;
            count++;
        }
    }

    printf("Sum of positive elements: %d\n", sum);
    printf("Count of positive elements: %d\n", count);

    return 0;
}