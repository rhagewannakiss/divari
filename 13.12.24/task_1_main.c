#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    Stack stack;
    StackCtor(&stack);

    int choice;
    do {
        DisplayMenu();
        printf("Enter choice: \n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                StackMenu(&stack);
                break;
        }
    } while (choice != 0);

    StackDtor(&stack);

    return 0;
}
