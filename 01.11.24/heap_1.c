#include <stdio.h>

#include "swap.h"
#include "heap_tree.h"

//Проверьте, представляет ли массив, введённый с клавиатуры  минимальную кучу или нет. Если да, то выведите YES если нет — NO.

int main() {
    int arr[] = {2, 3, 15, 8, 7, 54};
    int arr2[] = {1, 8, 15, 5, 6};

    for (int i = 0; i < sizeof(arr2)/sizeof(int); i++) {
        if ((arr2[i] <= arr2[i + 1]) || (arr2[i] <= arr2[i + 2])) {
            printf("yerrrss");
        }
        else printf("nopeee");
    }

    return 0;
}

