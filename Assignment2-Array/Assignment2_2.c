// Parunchai Kaewkhampa 66070503434
// AAssignment 2.2 : Jump Game

#include <stdio.h>
#include <stdlib.h>

int minJumps(int arr[], int start, int end);

int main(void)
{
    int n;
    scanf("%d", &n);
    if (0 > n || n > 1000)
    {
        // Invalid input (out of range)
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        // Memory allocation failed
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Print result
    int min = minJumps(arr, 0, n - 1);
    if (min == 1000)
    {
        printf("Not Possible\n");
    }
    else
    {
        printf("%d\n", min);
    }

    // Free memory
    free(arr);

    return 0;
}

int minJumps(int arr[], int start, int end)
{
    // Only one element is reachable
    if (end == start)
    {
        return 0;
    }

    // Value of start must be greater than 0,
    if (arr[start] == 0)
    {
        return 1000;
    }

    // Find the minimum number of jumps to reach arr[end] from arr[start].
    int min = 1000;
    for (int i = start + 1, j = start + arr[start]; i <= end && i <= j; i++)
    {
        int jumps = minJumps(arr, i, end);
        if (jumps != 1000 && jumps + 1 < min)
        {
            min = jumps + 1;
        }
    }

    return min;
}