#include <stdio.h>

void insertMinHeap(int heap_array[], int* array_size, int new_element);
void addElement();

int main() {
    addElement();

    return 0;
}

void insertMinHeap(int heap_array[], int* array_size, int new_element)
{
    (*array_size)++;
    heap_array[*array_size - 1] = new_element;

    for (int current_index = *array_size - 1; current_index != 0 && heap_array[(current_index - 1) / 2] > heap_array[current_index];)
    {
        int temp = heap_array[current_index];
        heap_array[current_index] = heap_array[(current_index - 1) / 2];
        heap_array[(current_index - 1) / 2] = temp;
        current_index = (current_index - 1) / 2;
    }

    return;
}

void addElement()
{
    int array_size;
    printf("Enter the number of elements: \n");
    scanf("%d", &array_size);

    int heap_array[array_size + 1];
    printf("Enter elements of the array: \n");
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &heap_array[i]);
    }

    int new_element;
    printf("Enter the value you would like to add to a heap: \n");
    scanf("%d", &new_element);

    insertMinHeap(heap_array, &array_size, new_element);

    printf("The heap after inserting your element: \n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", heap_array[i]);
    }
    printf("\n");

    return;
}
