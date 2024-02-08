// Parunchai Kaewkhampa 66070503434
// Lab 2.1 : No Bracket

#include <stdio.h>
#include <stdlib.h>

void printEvenIndex(int *arr, int n);
void printOddIndex(int *arr, int n);

int main(void)
{
    // Input n
    int n;
    scanf("%d", &n);
    if (1 > n || n > 10000)
    {
        // Invalid input (out of range)
        return 1;
    }

    // Input array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        // Out of memory
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    // Input mode
    int mode;
    scanf("%d", &mode);

    // print result
    switch (mode)
    {
    case 0:
        // print even index of array
        printEvenIndex(arr, n);
        break;
    case 1:
        // print odd index of array
        printOddIndex(arr, n);
        break;
    default:
        // Invalid mode
        return 1;
    }

    // Free memory
    free(arr);

    return 0;
}

void printEvenIndex(int *arr, int n)
{
    int c = 0;
    for (int i = 0; i < n; i += 2)
    {
        printf("%d ", *(arr + i));
        c++;
    }
    if (c == 0)
    {
        printf("none\n");
    }
}

void printOddIndex(int *arr, int n)
{
    int c = 0;
    for (int i = 1; i < n; i += 2)
    {
        printf("%d ", *(arr + i));
        c++;
    }
    if (c == 0)
    {
        printf("none\n");
    }
}