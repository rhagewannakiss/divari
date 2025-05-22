#include "lists.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// •	Создать односвязный список из 10 звеньев, значения элементов ввести.
Node* NodeCtor(const int value) {
    Node* new_node = (Node*)calloc(kMinNumOfElems, sizeof(Node));

    new_node->value = value;
    new_node->next =  NULL;

    return new_node;
}

// •	Добавить первое звено (вставка звена в голову).
void AddToHead(Node** head, const int value) {
    assert(head != NULL);

    Node* new_node = NodeCtor(value);

    new_node->next = *head;
                     *head = new_node;

    printf("Value %d has been successfully added to head.\n", value);
    return;
}

// •	Добавить последнее звено (вставка звена в хвост).
void AddToTail(Node** head, int value) {
    assert(head != NULL);

    Node* new_node = NodeCtor(value);

    if (*head == NULL) {
        prinf("Value %d has been successfully added to tail.\n", value);
        *head = new_node;

        return;
    }

    Node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;

    prinf("Value %d has been successfully added to tail.\n", value);
    return;
}

// •	Добавить звено до (или после) звена с введенным элементом.
void AddAfter(Node* head, const int target, const int value) {
    assert(head != NULL);

    Node* current = head;

    while (current != NULL && current->value != target) {
        current = current->next;
    }

    if (current != NULL) {
        Node* new_node = NodeCtor(value);

        new_node->next = current->next;
        current->next = new_node;
    } else {
        printf("Element %d not found in the list!\n", target);
    }

    return;
}

// •	Удалить первое звено.
void DeleteHead(Node** head) {
    assert(head != NULL);

    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = *head;
                 *head = (*head)->next;
    free(temp);

    return;
}

// •	Удалить последнее звено.
void DeleteTail(Node** head) {
    assert(head != NULL);

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* current = *head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    return;
}

// •	Удалить звено с введенным элементом.
void DeleteByValue(Node** head, const int value) {
    assert(head != NULL);

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->value == value) {
        DeleteHead(head);
        printf("Value %d has been deleted successfully.\n", value);
        return;
    }

    Node* current = *head;

    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
                     current->next = current->next->next;
        free(temp);
    } else {
        printf("Element %d not found in the list.\n", value);
    }

    return;
}

// •	Печать списка
void PrintList(Node* head) {
    Node* current = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    return;
}

// •	Записать список в файл.
void FreeList(Node** head) {
    Node *current = *head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;

    return;
}

void WriteListToFile(Node* head, const char* filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    Node* current = head;

    while (current != NULL) {
        fprintf(file, "%d\n", current->value);
        current = current->next;
    }

    fclose(file);

    return;
}
