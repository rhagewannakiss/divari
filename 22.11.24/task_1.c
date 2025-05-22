#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// ?  1.	Дано два отсортированных массива разной длины. Написать функцию, в которой за один проход скопировать эти два массива в третий (упорядоченный).
// ?  Передать полученный массив в вызывающую функцию и распечатать его в функции main.


void mergeArrays(int* arr1, int size1, int* arr2, int size2, int** mergedArray, int* mergedSize);

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6};

    int* mergedArray = NULL;
    int mergedSize;

    mergeArrays(arr1, 4, arr2, 3, &mergedArray, &mergedSize);

    printf("Merged Array: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    free(mergedArray);
    return 0;
}


void mergeArrays(int* arr1, int size1, int* arr2, int size2, int** mergedArray, int* mergedSize)
{
    assert(arr1 != NULL);
    assert(arr2 != NULL);
    assert(mergedArray != NULL);

    *mergedSize = size1 + size2;
    *mergedArray = (int*)malloc(*mergedSize * sizeof(int));

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            (*mergedArray)[k++] = arr1[i++];
        }
        else
        {
            (*mergedArray)[k++] = arr2[j++];
        }
    }

    while (i < size1)
    {
        (*mergedArray)[k++] = arr1[i++];
    }
    while (j < size2)
    {
        (*mergedArray)[k++] = arr2[j++];
    }

    return;
}