#include <stdio.h>

void deleteMinHeap(int heap_array[], int* array_size);
void removeElement();
void minHeapify(int heap_array[], int array_size, int parent_index);
void buildMinHeap(int heap_array[], int array_size);
void createMinHeap();

int main() {
    removeElement();
    return 0;
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

    int heap_array[array_size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &heap_array[i]);
    }

    deleteMinHeap(heap_array, &array_size);

    printf("Heap after having an element deleted: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", heap_array[i]);
    }
    printf("\n");

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

    int heap_array[array_size];
    printf("Enter elements of array: ");
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &heap_array[i]);
    }

    buildMinHeap(heap_array, array_size);

    printf("Minimal Heap: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", heap_array[i]);
    }
    printf("\n");

    return;
}