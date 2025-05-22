#include <stdio.h>
#include <assert.h>

#include <stdio.h>


int main()
{
    int x = 10;
    int y = 20;

    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(int));

    printf("After swap: x = %d, y = %d\n", x, y);

    double m = 1.5;
    double n = 2.5;

    printf("Before swap: m = %.1f, n = %.1f\n", m, n);
    swap(&m, &n, sizeof(double));

    printf("After swap: m = %.1f, n = %.1f\n", m, n);

    return 0;
}

void swap(void *a, void *b, size_t size)
{

    unsigned char* ptr_a = (unsigned char*)a;
    unsigned char* ptr_b = (unsigned char*)b;

    for (size_t i = 0; i < size; i++) {
        unsigned char temp = ptr_a[i];
                             ptr_a[i] = ptr_b[i];
                                        ptr_b[i] = temp;
    }

    return;
}