#ifndef TASK_2_H_
#define TASK_2_H

#define TABLE_SIZE        100

#define kMaxLineLength    256
#define kMaxCommandLength 10
#define kMaxKeyLength     128
#define kMaxValueLength   128


typedef struct Node {
    char*        key;
    char*        value;
    struct Node* next;
} Node;

typedef struct HashTable{
    Node** buckets;
} HashTable;


void         TableDtor(HashTable *table);
void         Delete(HashTable *table, const char *key);
const char*  Find(HashTable *table, const char *key) ;
void         Insert(HashTable *table, const char *key, const char *value);
HashTable*   TableCtor();
unsigned int Hash(const char *key);
void         Help();

#endif //TASK_2_H_