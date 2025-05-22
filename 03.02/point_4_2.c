#include <stdlib.h>
#include "point_4_2.h"

int main(void)
{
    struct Node_int* root = (struct Node_int*)calloc(ONE, sizeof(struct Node_int));
    push_int(&root, 5);

    return 0;
}

void push_int (struct Node_int **top, int a)
{
    ASSERT(*top, "top = NULL, it is impossible to work with null ptr", stderr);

    struct Node_int* newNodeInt = (struct Node_int*)calloc(ONE, sizeof(struct Node_int));
    ASSERT(newNodeInt, "newNodeInt = NULL, it is impossible to work with null ptr", stderr);

    newNodeInt->next = *top;
    newNodeInt->number = a;
    *top = newNodeInt;
}

int pop_int (struct Node_int **top)
{
    ASSERT(*top, "top = NULL, it is impossible to work with null ptr", stderr);

    int returnNumber = (*top)->number;
    struct Node_int* nextPtr = (*top)->next;

    (*top)->number = 0;
    (*top)->next = NULL;

    *top = nextPtr;

    return returnNumber;
}

bool isempty_int(struct Node_int *top)
{
    if (top)
        return true;

    return false;
}