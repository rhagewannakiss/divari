#include <stdio.h>
#include <stdlib.h>

void sortUsingHeapSort();
void heapSort(int unsorted_array[], int array_size);
void createMinHeap();
void buildMinHeap(int heap_array[], int array_size);
void minHeapify(int heap_array[], int array_size, int parent_index);

int main() {
    sortUsingHeapSort();

    return 0;
}

void heapSort(int unsorted_array[], int array_size)
{
    buildMinHeap(unsorted_array, array_size);

    for (int i = array_size - 1; i > 0; i--)
    {
        int temp = unsorted_array[0];
        unsorted_array[0] = unsorted_array[i];
        unsorted_array[i] = temp;

        minHeapify(unsorted_array, i, 0);
    }

    return;
}

void sortUsingHeapSort()
{
    int array_size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &array_size);

    if (array_size <= 0)
    {
        printf("Invalid array size.\n");
        return;
    }

    int unsorted_array[array_size];
    printf("Enter elements in the array: ");
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &unsorted_array[i]);
    }

    heapSort(unsorted_array, array_size);

    printf("Your sorted array: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", unsorted_array[i]);
    }
    printf("\n");

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

    int heap_array[array_size];
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
