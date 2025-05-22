#include <stdio.h>
float f(float *, unsigned);
int main()
{
    float a[] = {1, 2, 3, 4, 5,7,7,7,8,8,9,9,1,1,2,2,3};
    unsigned n;
    printf("Enter the number of elements for sum (max - %zu): ", sizeof(a) / sizeof(a[0])); // Добавлена инструкция для пользователя, чтобы не вводили значение n, большее, чем размер массива
    scanf("%u", &n);
    // Добавлена проверка на то, что введенное значение n не превышает размера массива для избегания ошибки
    if (n > sizeof(a) / sizeof(a[0])) {
        printf("ERROR: n is bigger than size of array! \n");
        return 1;
    }
    // Конец првоерки
    printf("%f\n", f(a, n));
    return 0;
}

float f(float *a, unsigned n)
{
    float s = 0.;
    int i;
    for (i = 0; i < n; i++) // "<=" изменено на "<" для предотвращения выхода за границы памяти
        s += a[i];
    return s;
}