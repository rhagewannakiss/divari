#include <stdio.h>

int  isMinHeap(int heap_array[], int array_size);
void checkMinHeap();

int main() {
    checkMinHeap();

    return 0;
}

int isMinHeap(int heap_array[], int array_size)
{
    for (int parent_index = 0; parent_index <= (array_size - 2) / 2; parent_index++)
    {
        int left_child_index = 2 * parent_index + 1;
        int right_child_index = 2 * parent_index + 2;

        if (heap_array[parent_index] > heap_array[left_child_index])
        {
            return 0;
        }
        if (right_child_index < array_size && heap_array[parent_index] > heap_array[right_child_index])
        {
            return 0;
        }
    }
    return 1;
}

void checkMinHeap()
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

    if (isMinHeap(heap_array, array_size))
    {
        printf("YES\n");
    } else
    {
        printf("NO\n");
    }

    return;
}