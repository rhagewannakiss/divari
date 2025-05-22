#include "task_2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


//------------------------ MAIN -------------------------------

int main() {
    HashTable* dict = TableCtor();
    char line[kMaxLineLength];

    printf("=== Hash Table Manager ===\n");
    printf("Type 'HELP' for commands list\n\n");

    while (1) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) break;

        line[strcspn(line, "\n")] = 0;

        if (strcasecmp(line, "HELP") == 0) {
            Help();
        }
        else if (strcasecmp(line, "EXIT") == 0) {
            printf("Exiting...\n");
            break;
        }
        else {
            char cmd[kMaxCommandLength], key[kMaxKeyLength], value[kMaxValueLength];
            if (sscanf(line, "ADD %127s %127[^\n]", key, value) == 2) {
                Insert(dict, key, value);
                printf("Entry added\n");
            }
            else if (sscanf(line, "FIND %127s", key) == 1) {
                const char* result = Find(dict, key);
                printf("%s\n", result ? result : "Not found");
            }
            else if (sscanf(line, "DELETE %127s", key) == 1) {
                Delete(dict, key);
                printf("Entry deleted\n");
            }
            else {
                printf("Invalid command. Type HELP for instructions\n");
            }
        }
    }

    TableDtor(dict);

    return 0;
}

//-------------------------------------------------------------


void Help() {
    printf("===============================================================================================================\n");
    printf("\nAvailable commands:\n");
    printf("  ADD <key> <value>   - Add new entry (max key: %d chars, value: %d chars)\n", kMaxKeyLength-1, kMaxValueLength-1);
    printf("  FIND <key>          - Search for value by key (case-insensitive)\n");
    printf("  DELETE <key>        - Remove entry from table\n");
    printf("  HELP                - Show this help\n");
    printf("  EXIT                - Exit program\n\n");
    printf("===============================================================================================================\n");

    return;
}

unsigned int Hash(const char *key) {
    assert(key != NULL);
    unsigned int hash = 0;

    for (; *key; key++) {
        hash = (hash * 31 + tolower(*key)) % TABLE_SIZE;
    }

    return hash;
}

HashTable* TableCtor() {
    HashTable *table = calloc(1, sizeof(HashTable));
    assert(table != NULL);

    table->buckets = calloc(TABLE_SIZE, sizeof(Node*));
    assert(table->buckets != NULL);

    return table;
}

void Insert(HashTable *table, const char *key, const char *value) {
    assert(table != NULL);
    assert(key != NULL);
    assert(value != NULL);
    assert(strlen(key) < kMaxKeyLength);
    assert(strlen(value) < kMaxValueLength);

    unsigned int index = Hash(key);
    Node *current = table->buckets[index];

    while (current != NULL) {
        if (strcasecmp(current->key, key) == 0) {
            free(current->value);
            current->value = strndup(value, kMaxValueLength-1);
            return;
        }
        current = current->next;
    }

    Node *new_node = malloc(sizeof(Node));
    assert(new_node != NULL);

    new_node->key = strndup(key, kMaxKeyLength-1);
    new_node->value = strndup(value, kMaxValueLength-1);
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;

    return;
}

const char* Find(HashTable *table, const char *key) {
    assert(table != NULL);
    assert(key != NULL);

    unsigned int index = Hash(key);
    Node *current = table->buckets[index];

    while (current != NULL) {
        if (strcasecmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

void Delete(HashTable *table, const char *key) {
    assert(table != NULL);
    assert(key != NULL);

    unsigned int index = Hash(key);
    Node *current = table->buckets[index];
    Node *prev = NULL;

    while (current != NULL) {
        if (strcasecmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }

            free(current->key);
            free(current->value);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    return;
}

void TableDtor(HashTable* table) {
    assert(table != NULL);

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = table->buckets[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(table->buckets);
    free(table);

    return;
}