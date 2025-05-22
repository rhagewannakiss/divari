#include <stdio.h>
#include <stdlib.h>

void extractSortedArray(int heap_array[], int* array_size, int sorted_array[]);
void SortArray();
void deleteMinHeap(int heap_array[], int* array_size);
void removeElement();
void minHeapify(int heap_array[], int array_size, int parent_index);
void buildMinHeap(int heap_array[], int array_size);
void createMinHeap();
void readArray(int heap_array[], int* array_size, const char* prompt);

int main()
{
    SortArray();
    return 0;
}

void readArray(int heap_array[], int* array_size, const char* prompt)
{
    printf("%s", prompt);
    scanf("%d", array_size);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < *array_size; i++)
    {
        scanf("%d", &heap_array[i]);
    }

    return;
}

void extractSortedArray(int heap_array[], int* array_size, int sorted_array[])
{
    int original_size = *array_size;
    for (int i = 0; i < original_size; i++) {
        sorted_array[i] = heap_array[0];
        deleteMinHeap(heap_array, array_size);
    }

    return;
}

void SortArray()
{
    int array_size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &array_size);

    if (array_size <= 0)
    {
        printf("Invalid array size.\n");
        return;
    }

    int* heap_array = (int*)malloc(array_size * sizeof(int));
    int* sorted_array = (int*)malloc(array_size * sizeof(int));

    if (!heap_array || !sorted_array)
    {
        printf("Memory allocation failed.\n");
        free(heap_array);
        free(sorted_array);
        return;
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &heap_array[i]);
    }

    int original_size = array_size;

    buildMinHeap(heap_array, array_size);
    extractSortedArray(heap_array, &array_size, sorted_array);

    printf("Your sorted array: ");
    for (int i = 0; i < original_size; i++)
    {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    free(heap_array);
    free(sorted_array);

    return;
}

void deleteMinHeap(int heap_array[], int* array_size)
{
    if (*array_size <= 0)
    {
        return;
    }

    heap_array[0] = heap_array[*array_size - 1];
    (*array_size)--;

    minHeapify(heap_array, *array_size, 0);

    return;
}

void removeElement()
{
    int array_size;
    printf("Enter the number of elements: ");
    scanf("%d", &array_size);

    if (array_size <= 0)
    {
        printf("Invalid array size.\n");
        return;
    }

    int* heap_array = (int*)malloc(array_size * sizeof(int));
    if (!heap_array)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter elements of the array: ");
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &heap_array[i]);
    }

    deleteMinHeap(heap_array, &array_size);

    printf("Heap after deleting an element: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", heap_array[i]);
    }
    printf("\n");

    free(heap_array);

    return;
}

void minHeapify(int heap_array[], int array_size, int parent_index)
{
    int smallest_index = parent_index;
    int left_child_index = 2 * parent_index + 1;
    int right_child_index = 2 * parent_index + 2;

    if (left_child_index < array_size && heap_array[left_child_index] < heap_array[smallest_index])
    {
        smallest_index = left_child_index;
    }
    if (right_child_index < array_size && heap_array[right_child_index] < heap_array[smallest_index])
    {
        smallest_index = right_child_index;
    }
    if (smallest_index != parent_index)
    {
        int temp = heap_array[parent_index];
        heap_array[parent_index] = heap_array[smallest_index];
        heap_array[smallest_index] = temp;
        minHeapify(heap_array, array_size, smallest_index);
    }

    return;
}

void buildMinHeap(int heap_array[], int array_size)
{
    for (int parent_index = array_size / 2 - 1; parent_index >= 0; parent_index--)
    {
        minHeapify(heap_array, array_size, parent_index);
    }

    return;
}

void createMinHeap()
{
    int array_size;
    printf("Enter the number of elements: ");
    scanf("%d", &array_size);

    if (array_size <= 0)
    {
        printf("Invalid array size.\n");
        return;
    }

    int* heap_array = (int*)malloc(array_size * sizeof(int));
    if (!heap_array)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter elements of the array: ");
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &heap_array[i]);
    }

    buildMinHeap(heap_array, array_size);

    printf("Min Heap: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", heap_array[i]);
    }
    printf("\n");

    free(heap_array);

    return;
}
