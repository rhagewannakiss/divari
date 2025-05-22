//n-ый член последовательности треугольных чисел задается как t_tp = n * (n + 1) / 2
//1, 3, 6, 10, 15, 21, 28, 36, 45, 55
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void listMenu(Node **head) {
    int choice, value, target;
    do {
        printf("\nSingly Linked List Menu:\n");
        printf("1. Add to head\n");
        printf("2. Add to tail\n");
        printf("3. Add after value\n");
        printf("4. Delete head\n");
        printf("5. Delete tail\n");
        printf("6. Delete by value\n");
        printf("7. Print list\n");
        printf("8. Write list to file\n");
        printf("9. Free list\n");
        printf("0. Back to main menu\n");
        printf("Enter choice: \n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add to head: ");
                scanf("%d", &value);
                addToHead(head, value);
                break;
            case 2:
                printf("Enter value to add to tail: ");
                scanf("%d", &value);
                addToTail(head, value);
                break;
            case 3:
                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter value to add after %d: ", target);
                scanf("%d", &value);
                addAfter(*head, target, value);
                break;
            case 4:
                deleteHead(head);
                break;
            case 5:
                deleteTail(head);
                printf("Tail has been deleted successfully.\n");
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(head, value);
                break;
            case 7:
                printList(*head);
                break;
            case 8:
                writeListToFile(*head, "list.txt");
                break;
            case 9:
                freeList(head);
                break;
        }
    } while (choice != 0);
}


// Singly linked list
typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void addToHead(Node **head, int value) {
    Node *new_node = createNode(value);
    new_node->next = *head;
    *head = new_node;
}

void addToTail(Node **head, int value) {
    Node *new_node = createNode(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void addAfter(Node *head, int target, int value) {
    Node *current = head;
    while (current != NULL && current->value != target) {
        current = current->next;
    }
    if (current != NULL) {
        Node *new_node = createNode(value);
        new_node->next = current->next;
        current->next = new_node;
    } else {
        printf("Element %d not found in the list!\n", target);
    }
}

void deleteHead(Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteTail(Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void deleteByValue(Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->value == value) {
        deleteHead(head);
        return;
    }
    Node *current = *head;
    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }
    if (current->next != NULL) {
        Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    } else {
        printf("Element %d not found in the list!\n", value);
    }
}

void printList(Node *head) {
    Node *current = head;
    printf("List elements: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void freeList(Node **head) {
    Node *current = *head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

void writeListToFile(Node *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file!\n");
        return;
    }
    Node *current = head;
    while (current != NULL) {
        fprintf(file, "%d\n", current->value);
        current = current->next;
    }
    fclose(file);
}