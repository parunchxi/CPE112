// Parunchai Kaewkhampa 66070503434
// Lab 2.4 : Array Manipulation

#include <stdio.h>
#include <stdlib.h>

void insertArray(int *arr, int *size, int index, int value);
void deleteArray(int *arr, int *size, int index);
int *mergeArray(int *arr1, int size1, int *arr2, int size2);
void printArray(int arr[], int size);

int main(void)
{
    // Input number of first array
    int n1;
    scanf("%d", &n1);
    if (1 > n1 || n1 > 10000)
    {
        // Invalid input (out of range)
        return 1;
    }
    // Input elements of first array
    int *arr1 = (int *)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", arr1 + i);
    }

    // Input number of second array
    int n2;
    scanf("%d", &n2);
    if (1 > n2 || n2 > 10000)
    {
        // Invalid input (out of range)
        return 1;
    }
    // Input elements of second array
    int *arr2 = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", arr2 + i);
    }

    // Input index and value to insert, index to delete
    int insertIndex, insertValue, deleteIndex;
    scanf("%d %d %d", &insertIndex, &insertValue, &deleteIndex);

    // Insert value to first array
    insertArray(arr1, &n1, insertIndex, insertValue);

    // Delete value from first array
    deleteArray(arr1, &n1, deleteIndex);

    // Merge two arrays
    int *arr = mergeArray(arr1, n1, arr2, n2);
    printArray(arr, n1 + n2);

    // Free memory
    free(arr1);
    free(arr2);

    return 0;
}

void insertArray(int *arr, int *size, int index, int value)
{
    // Check if index is out of bounds
    if (index < 0 || index > *size)
    {
        printf("Index out of bounds\n");
        return;
    }

    // Increase size of array
    (*size)++;

    // Move elements to the right
    for (int i = *size - 1; i > index; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }

    // Insert value
    *(arr + index) = value;

    // Print array
    printArray(arr, *size);
}

void deleteArray(int *arr, int *size, int index)
{
    // Check if index is out of bounds
    if (index < 0 || index >= *size)
    {
        printf("Index out of bounds\n");
        return;
    }

    // Move elements to the left
    for (int i = index; i < *size - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }

    // Decrease size of array
    (*size)--;

    // Print array
    printArray(arr, *size);
}

int *mergeArray(int *arr1, int size1, int *arr2, int size2)
{
    // Create new array
    int *arr = (int *)malloc((size1 + size2) * sizeof(int));

    // Copy elements from first array
    for (int i = 0; i < size1; i++)
    {
        *(arr + i) = *(arr1 + i);
    }

    // Copy elements from second array
    for (int i = 0; i < size2; i++)
    {
        *(arr + size1 + i) = *(arr2 + i);
    }

    return arr;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}