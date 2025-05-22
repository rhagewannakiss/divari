#ifndef HEAP_TREE_
#define HEAP_TREE_

typedef int elem_t;
typedef size_t index_t;

typedef struct heap_t {
    elem_t value;

    index_t right;
    index_t left;
} heap_t;

typedef struct tree_t {
    heap_t* kids[];
    index_t free_heap;
} tree_t;

#endif //HEAP_TREE_