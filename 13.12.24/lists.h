#ifndef STACK_H_
#define STACK_H_

static const int kMinNumOfElems =     8;
static const int kMultiplier =        2;
static const int kDivForReallocDown = 4;


typedef struct Node {
    int   value;

    Node* next;
} Node;

Node* NodeCtor(const int value);
void AddToHead(Node** head, const int value);
void AddToTail(Node** head, int value);
void AddAfter(Node* head, const int target, const int value);
void DeleteHead(Node** head);
void DeleteTail(Node** head);
void DeleteByValue(Node** head, const int value);
void PrintList(Node* head);
void FreeList(Node** head);
void WriteListToFile(Node* head, const char* filename);

#endif //LISTS_H_