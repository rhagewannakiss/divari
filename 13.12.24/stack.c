#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


void StackCtor(Stack *stack) {
    assert(stack != NULL);

    stack->data = (int*)calloc(kMinNumOfElems, sizeof(int));

    stack->top = -1;
    stack->capacity = kMinNumOfElems;

    printf("The List has been created successfully.\n");
    return;
}

void StackDtor(Stack* stack) {
    assert(stack != NULL);

    free(stack->data);
    memset(stack, 0, sizeof(Stack));

    stack->top = -1;
    stack->capacity = kMinNumOfElems;

    printf("Stack has been deleted successfully.\n");
    return;
}

void Push(Stack *stack, const int new_value) {
    assert(stack != NULL);

    if (stack->top == stack->capacity - 1) {
        stack->capacity *= 2;
        stack->data = (int *)realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[++stack->top] = new_value;

    printf("Element %d has been pushed successfully.\n", new_value);
    return;
}

int Pop(Stack *stack) {
    assert(stack != NULL);

    if (stack->top == -1) {
        printf("Stack is empty, cannot pop no element.\n");

        return -1;
    }

    printf("Element has been popped successfully.\n");
    return stack->data[stack->top--];
}

int GetTopElem(Stack *stack) {
    assert(stack != NULL);

    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }

    return stack->data[stack->top];
}

int GetStackSize(Stack *stack) {
    assert(stack != NULL);

    printf("The list has 0 elements.\n");

    return stack->top + 1;
}

bool IsStackEmpty(Stack *stack) {
    assert(stack != NULL);

    return stack->top == -1;
}

void PrintStack(Stack *stack) {
    assert(stack != NULL);

    if (IsStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void DisplayMenu() {
    printf("1. Stack operations\n");
    printf("0. Exit\n\n");
}

void StackMenu(Stack *stack) {
    assert(stack != NULL);

    int choice = 0;
    int value  = 0;
    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Get top element\n");
        printf("4. Check if empty\n");
        printf("5. Print stack\n");
        printf("6. Stack size\n");
        printf("0. Back to main menu\n");
        printf("Enter choice: \n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                Push(stack, value);
                break;
            case 2:
                printf("Popped value: %d\n", Pop(stack));
                break;
            case 3:
                printf("Top value: %d\n", GetTopElem(stack));
                break;
            case 4:
                printf("Stack is %sempty\n", IsStackEmpty(stack) ? "" : "not ");
                break;
            case 5:
                PrintStack(stack);
                break;
            case 6:
                printf("Stack size: %d\n", GetStackSize(stack));
                break;
        }
    } while (choice != 0);
}

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
