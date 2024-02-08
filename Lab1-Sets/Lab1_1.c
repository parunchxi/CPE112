// Parunchai Kaewkhampa 66070503434
// Lab 1.1 : Set.

#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if (1 > n || n > 1000)
    {
        // Invalid input (out of range)
        return 1;
    }
    int sn[n], sm[n], m = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sn[i]);
        if (i == 0)
        {
            // First element
            sm[m] = sn[i];
            m++;
        }
        else if (i > 0 && sn[i] < sn[i - 1])
        {
            // Invalid input (not non-decreasing)
            return 1;
        }
        else if (i > 0 && sn[i] != sn[i - 1])
        {
            // Unique element
            sm[m] = sn[i];
            m++;
        }
    }
    // Print the result
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
    {
        printf("%d ", sm[i]);
    }
    return 0;
}