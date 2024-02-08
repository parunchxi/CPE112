// Parunchai Kaewkhampa 66070503434
// Lab 2.2 : No Bracket No Printf

#include <stdio.h>
#include <stdlib.h>

void findMinMax(int *arr, int n, int *min, int *max, int *minIndex, int *maxIndex);
void print(int a, int b);

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

    // Find min and max
    int min, max, minIndex = 0, maxIndex = 0;
    findMinMax(arr, n, &min, &max, &minIndex, &maxIndex);

    // Print result
    print(max, maxIndex);
    print(min, minIndex);

    // Free memory
    free(arr);

    return 0;
}

void findMinMax(int *arr, int n, int *min, int *max, int *minIndex, int *maxIndex)
{
    *min = *max = *arr;
    for (int i = 1; i < n; i++)
    {
        int temp = *(arr + i);
        if (temp < *min)
        {
            *min = temp;
            *minIndex = i;
        }
        if (temp > *max)
        {
            *max = temp;
            *maxIndex = i;
        }
    }
}

void print(int a, int b)
{
    printf("%d %d\n", a, b);
}