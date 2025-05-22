#include <stdio.h>
#include <stdlib.h>

void minHeapify(int heap_array[], int array_size, int parent_index);
void buildMinHeap(int heap_array[], int array_size);
void heapSort(int unsorted_array[], int array_size);
void mergeHeaps(int heap_array1[], int size1, int heap_array2[], int size2, int merged_array[]);
void mergeHeapsExample();

//сделать слитие в то место где получится сразу минимальная куча


int main()
{
    mergeHeapsExample();
    return 0;
}

void mergeHeaps(int heap_array1[], int size1, int heap_array2[], int size2, int merged_array[])
{
    for (int i = 0; i < size1; i++)
    {
        merged_array[i] = heap_array1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        merged_array[size1 + i] = heap_array2[i];
    }

    buildMinHeap(merged_array, size1 + size2);

    return;
}

void mergeHeapsExample()
{
    int size1, size2;

    printf("Enter the number of elements in the first heap: ");
    scanf("%d", &size1);

    int* heap_array1 = (int*)malloc(size1 * sizeof(int));
    if (!heap_array1)
    {
        printf("Memory allocation failed for first heap.\n");
        return;
    }
    printf("Enter the elements of the first heap: ");
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &heap_array1[i]);
    }

    printf("Enter the number of elements in the second heap: ");
    scanf("%d", &size2);

    int* heap_array2 = (int*)malloc(size2 * sizeof(int));
    if (!heap_array2)
    {
        printf("Memory allocation failed for second heap.\n");
        free(heap_array1);
        return;
    }
    printf("Enter the elements of the second heap: ");
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &heap_array2[i]);
    }

    int merged_size = size1 + size2;
    int* merged_array = (int*)malloc(merged_size * sizeof(int));
    if (!merged_array)
    {
        printf("Memory allocation failed for merged array.\n");
        free(heap_array1);
        free(heap_array2);
        return;
    }

    mergeHeaps(heap_array1, size1, heap_array2, size2, merged_array);

    printf("Merged and sorted heap: ");
    for (int i = 0; i < merged_size; i++)
    {
        printf("%d ", merged_array[i]);
    }
    printf("\n");

    free(heap_array1);
    free(heap_array2);
    free(merged_array);

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
