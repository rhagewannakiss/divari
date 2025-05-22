#ifndef TASK_1_H_
#define TASK_1_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100
#define DELETED_NODE (Person*)(0xFFFFFFFFFFFFFFFFUL)

#define kMaxCommandLength 128
#define kMaxNameLength    128
#define kMaxPhoneLength   15

typedef struct Person{
    char name[kMaxNameLength];
    char phone[kMaxPhoneLength];
} Person;

typedef struct HashTable{
    Person* data[TABLE_SIZE];
} HashTable;

unsigned int Hash(const char* key);
void         TableCtor(HashTable* table);
void         TableDtor(HashTable* table);
int          FindIndex(HashTable* table, const char* name, int for_insert);
void         AddPerson(HashTable* table, const char* name, const char* phone);
void         FindPerson(HashTable* table, const char* name);
void         DeletePerson(HashTable* table, const char* name);
void         Help();

#endif //TASK_1_H_