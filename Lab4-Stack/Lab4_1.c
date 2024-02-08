// Parunchai Kaewkhampa 66070503434
// Lab 4.1 Stack Array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void push(int *arr, int *top, int size, int value);
void pop(int *arr, int *top);
void show(int *arr, int *top);
bool isFull(int *top, int size);
bool isEmpty(int *top);

int main(void)
{
    // Input size, initialize top and stack array.
    int size, top = -1;
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Please enter a positive number.\n");
        return 1;
    }
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Menu
    int choice, value;
    while (scanf("%d", &choice) == 1)
    {
        switch (choice)
        {
        case 1:
            // Push
            scanf("%d", &value);
            push(arr, &top, size, value);
            break;
        case 2:
            // Pop
            pop(arr, &top);
            break;
        case 3:
            // Show
            show(arr, &top);
            break;
        case 4:
            // Exit
            printf("Exiting...\n");
            free(arr);
            return 0;
        default:
            printf("Invalid choice.\n");
            return 1;
        }
    }
}

void push(int *arr, int *top, int size, int value)
{
    if (isFull(top, size))
    {
        printf("Stack Overflow.\n");
        exit(1);
    }
    else
    {
        *top = *top + 1;
        arr[*top] = value;
    }
}

void pop(int *arr, int *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow.\n");
        exit(1);
    }
    else
    {
        *top = *top - 1;
    }
}

void show(int *arr, int *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty.\n");
        exit(1);
    }
    else
    {
        for (int i = *top; i >= 0; i--)
        {
            printf("%d\n", arr[i]);
        }
    }
}

bool isFull(int *top, int size)
{
    return *top == size - 1;
}

bool isEmpty(int *top)
{
    return *top == -1;
}
