#include "task_1.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//-------------------------- MAIN ------------------------------

int main() {
    HashTable table;
    TableCtor(&table);

    char command[kMaxCommandLength];
    char name[kMaxNameLength];
    char phone[kMaxPhoneLength];

    printf("Type 'HELP' for list of commands\n");

    while (fgets(command, sizeof(command), stdin)) {
        command[strcspn(command, "\n")] = 0;
        if (sscanf(command, "ADD %s %s", name, phone) == 2) {
            AddPerson(&table, name, phone);
        } else if (sscanf(command, "FIND %s", name) == 1) {
            FindPerson(&table, name);
        } else if (sscanf(command, "DELETE %s", name) == 1) {
            DeletePerson(&table, name);
        } else if (strcmp(command, "HELP") == 0) {
            Help();
        } else if (strcmp(command, "EXIT") == 0) {
            printf("Exiting program...\n");
            TableDtor(&table);
            return 0;
        } else {
            printf("Invalid command\n");
        }
    }

    TableDtor(&table);

    return 0;
}

//-------------------------------------------------------------


void TableCtor(HashTable* table) {
    assert(table != NULL);

    for (int i = 0; i < TABLE_SIZE; i++) {
        table->data[i] = NULL;
    }

    return;
}

void TableDtor(HashTable* table) {
    assert(table != NULL);

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->data[i] != NULL && table->data[i] != DELETED_NODE) {
            free(table->data[i]);
        }
        table->data[i] = NULL;
    }

    return;
}

unsigned int Hash(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = hash * 31 + *key++;
    }
    return hash % TABLE_SIZE;
}

int FindIndex(HashTable* table, const char* name, int for_insert) {
    unsigned int index = Hash(name);
    int start = index;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->data[index] == NULL ||
           (for_insert && table->data[index] == DELETED_NODE)) {
                return index;
           }
        if (table->data[index] != DELETED_NODE && strcmp(table->data[index]->name, name) == 0) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

void AddPerson(HashTable* table, const char* name, const char* phone) {
    assert(table != NULL);
    assert(name  != NULL);
    assert(phone != NULL);

    int index = FindIndex(table, name, 1);
    if (index == -1) {
        printf("Table is full!\n");
        return;
    }

    Person* p = calloc(1, sizeof(Person));

    strncpy(p->name, name, kMaxNameLength - 1);
    strncpy(p->phone, phone, kMaxPhoneLength - 1);

    table->data[index] = p;

    printf("Added succesfully.\n");
    return;
}

void FindPerson(HashTable* table, const char* name) {
    assert(table != NULL);
    assert(name  != NULL);

    int index = FindIndex(table, name, 0);
    if (index == -1 || table->data[index] == NULL || table->data[index] == DELETED_NODE) {
        printf("Not found\n");
    } else {
        printf("%s\n", table->data[index]->phone);
    }

    return;
}

void DeletePerson(HashTable* table, const char* name) {
    assert(table != NULL);
    assert(name  != NULL);

    int index = FindIndex(table, name, 0);
    if (index != -1 && table->data[index] != NULL && table->data[index] != DELETED_NODE) {
        free(table->data[index]);
        table->data[index] = DELETED_NODE;
    }

    printf("Deleted successufully.\n\n");

    return;
}

void Help() {
    printf("===============================================================================================================\n");
    printf("\nAVAILABLE COMMANDS:\n");
    printf("  ADD <name> <phone>    - Add new person and their phone number (e.g. ADD Misha 89257543210)\n");
    printf("  FIND <name>           - Search for a phone number by name (e.g. FIND Misha --> 89257543210\n");
    printf("  DELETE <name>         - Remove the person from the table (e.g. DELETE Misha --> Deleted successufully.)\n\n");
    printf("  HELP                  - Show this help message\n\n");
    printf("  EXIT                  - Exit programm\n\n");
    printf("Please be aware that:\n");
    printf("- Maximum name length: %d characters\n", kMaxNameLength-1);
    printf("- Phone format: up to %d digits\n\n", kMaxPhoneLength-1);
    printf("===============================================================================================================\n\n");

    return;
}