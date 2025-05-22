#include <stdio.h>


int test(int x, int y);

int main() {
    printf("%d\n", test(-5, -4));
    return 0;
}


int test(int x, int y) {
    int val = x;

    if (x < -3) {
        if (x > y) {
            val = x * y;
        } else {
            val = x + y;
        }
    } else if (x <= 2) {
        val = x ^ y;
    } else {
        val = x - y;
    }
    return val;
}