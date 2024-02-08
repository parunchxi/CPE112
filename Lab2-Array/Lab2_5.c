// Parunchai Kaewkhampa 66070503434
// Lab 2.5 : List Slicing

#include <stdio.h>
#include <stdlib.h>

typedef struct LIST
{
    int size;
    int *arr;
} LIST_T;

LIST_T *initList();

void append(LIST_T *list, int val);
void printList(LIST_T *list);
int assignStartEnd(int idx, int size);
LIST_T *slice(LIST_T *list, int start, int end, int step);
void freeList(LIST_T *list);

int main()
{
    // Initialize the list
    LIST_T *list = initList();
    // Input size of the list
    int n;
    scanf("%d", &n);
    if (n < 1 || n > 1000000)
    {
        // Invalid size
        return 1;
    }
    // Input the list
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        append(list, temp);
    }
    // Input the start, end, and step
    int start, end, step;
    scanf("%d %d %d", &start, &end, &step);

    // Print the sliced list
    LIST_T *sliced = slice(list, start, end, step);
    printList(sliced);

    // Free the memory to prevent memory leak
    freeList(list);
    freeList(sliced);

    return 0;
}

LIST_T *initList()
{
    LIST_T *list = (LIST_T *)malloc(sizeof(LIST_T));
    list->size = 0;
    list->arr = NULL;
    return list;
}

void append(LIST_T *list, int val)
{
    list->size++;
    list->arr = (int *)realloc(list->arr, list->size * sizeof(int));
    list->arr[list->size - 1] = val;
}

void printList(LIST_T *list)
{
    if (list->size == 0)
    {
        printf("empty\n");
        return;
    }

    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

int assignStartEnd(int idx, int size)
{
    // Negative index = counting from the end.
    if (idx < 0)
    {
        idx = size + idx;
    }
    // Ensure the index is non-negative.
    if (idx < 0)
    {
        idx = 0;
    }
    // Ensure the index is within bounds.
    else if (idx > size)
    {
        idx = size;
    }

    return idx;
}

LIST_T *slice(LIST_T *list, int start, int end, int step)
{
    // Initialize the sliced list
    LIST_T *sliced = initList();
    // Assign the start and end index
    start = assignStartEnd(start, list->size);
    end = assignStartEnd(end, list->size);

    if (start == list->size && step < 0)
    {
        start--;
    }

    // If the step is 0, return the empty list.
    if (step == 0)
    {
        return sliced;
    }

    if (step > 0)
    {
        for (int i = start; i < end; i += step)
        {
            append(sliced, list->arr[i]);
        }
    }
    else
    {
        for (int i = start; i > end; i += step)
        {
            append(sliced, list->arr[i]);
        }
    }

    return sliced;
}

void freeList(LIST_T *list)
{
    free(list->arr);
    free(list);
}