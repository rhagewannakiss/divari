#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static const int kMinNumOfElems =     8;
static const int kMultiplier =        2;
static const int kDivForReallocDown = 4;

typedef struct Stack{
    int *data;

    int top;
    int capacity;
} Stack;

void StackCtor(Stack *stack);
void StackDtor(Stack* stack);

void Push(Stack *stack, const int value);
int  Pop(Stack *stack);
int  GetTopElem(Stack *stack);
int  GetStackSize(Stack *stack);
bool IsStackEmpty(Stack *stack);
void PrintStack(Stack *stack);

void DisplayMenu();
void StackMenu(Stack *stack);


#endif //STACK_H_