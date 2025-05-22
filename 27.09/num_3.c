#include <stdio.h>
#include  <math.h>

//Напишите функцию, которая определит, является ли введенное число x степенью
//введенного числа k. Если да, то напечатать YES и NO в противном случае. И если
//да, то какой степени.

int check_power (size_t num, size_t base);

int main() {
    printf("Enter values x and k: \n");

    int x = 0;
    int k = 0;

    scanf("%d %d", &x, &k);

    if (check_power(x, k) == 1) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}

int check_power (size_t num, size_t base) {
    size_t i = 0;
    while ((int)floor(powl(base, i)) <= num)  {
        i++;
    }
    printf(" %ld \n", i);

    size_t max_power = i - 1;

    while (num > 0) {
        if ((i == max_power + 1) && (num / (int)floor(powl(base, i - 1)) == 1)) {
        }
        else if ((i != max_power + 1) && (num / (int)floor(powl(base, i - 1)) == 0)) {
        }
        else {
            return 0;
        }
        num = num % (int)floor(powl(base, i - 1));
        i--;

    }
    return 1;
}
