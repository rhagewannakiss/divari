#ifndef CHAR_STACK_H
#define CHAR_STACK_H

#include <stdbool.h>

struct Node {
    char elem;
    struct Node *next;
};

struct Node *push(struct Node *top, char a);
struct Node *pop(struct Node *top, char *a);
bool         isempty(struct Node *top);

#endif
