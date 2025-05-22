#include <stdio.h>

// Вводить целые знаковые числа до конца ввода и найти сумму положительных, // минимальный из введенных и количество отрицательных элементов.

int main() {
    int num = 0;
    int min_all = 0;
    int sum_positive = 0;
    int count_negative = 0;

    printf("Enter integers (press Ctrl+D to finish input):\n");

    scanf("%d", &num);
    min_all = num;

    if (num > 0) {
        sum_positive += num;
    }
    else {
        count_negative++;
    }

    while (scanf("%d", &num) == 1) {
        if (num > 0) {
            sum_positive += num;
        }
        else {
            count_negative++;
        }

        if (num < min_all) {
            min_all = num;
        }
    }

    printf("Sum of positive elements: %d\n", sum_positive);

    printf("Minimum of all elements: %d\n", min_all);

    printf("Count of negative elements: %d\n", count_negative);

    return 0;
}