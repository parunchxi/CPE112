// Parunchai Kaewkhampa 66070503434
// Lab 1.2 : The foundation of set

#include <stdio.h>

void printArr(int n, int arr[])
{
    if (n == 0)
    {
        printf("empty\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int getSet(int *size, int *arr, int m, int n)
{
    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < m || arr[i] > n || i > 0 && arr[i] == arr[i - 1])
        {
            i--;
            (*size)--;
        }
    }
}

void genUniverse(int m, int n, int *u)
{
    for (int i = 0; i < n - m + 1; i++)
    {
        u[i] = m + i;
    }
}

void Union(int sizeA, int sizeB, int A[], int B[])
{
    int C[sizeA + sizeB];
    int sizeC = 0;
    int iA = 0, iB = 0;
    while (iA < sizeA && iB < sizeB)
    {
        if (A[iA] < B[iB])
        {
            C[sizeC] = A[iA];
            iA++;
            sizeC++;
        }
        else if (A[iA] > B[iB])
        {
            C[sizeC] = B[iB];
            iB++;
            sizeC++;
        }
        else
        {
            C[sizeC] = A[iA];
            iA++;
            iB++;
            sizeC++;
        }
    }
    while (iA < sizeA)
    {
        C[sizeC] = A[iA];
        iA++;
        sizeC++;
    }
    while (iB < sizeB)
    {
        C[sizeC] = B[iB];
        iB++;
        sizeC++;
    }

    printArr(sizeC, C);
}

void Intersection(int sizeA, int sizeB, int A[], int B[])
{
    int C[sizeA + sizeB];
    int sizeC = 0;
    int iA = 0, iB = 0;
    while (iA < sizeA && iB < sizeB)
    {
        if (A[iA] < B[iB])
        {
            iA++;
        }
        else if (A[iA] > B[iB])
        {
            iB++;
        }
        else
        {
            C[sizeC] = A[iA];
            iA++;
            iB++;
            sizeC++;
        }
    }

    printArr(sizeC, C);
}

void Difference(int sizeA, int sizeB, int A[], int B[])
{
    // difference (A-B)
    int C[sizeA];
    int sizeC = 0;
    int iA = 0, iB = 0;
    while (iA < sizeA && iB < sizeB)
    {
        if (A[iA] < B[iB])
        {
            C[sizeC] = A[iA];
            iA++;
            sizeC++;
        }
        else if (A[iA] > B[iB])
        {
            iB++;
        }
        else
        {
            iA++;
            iB++;
        }
    }
    while (iA < sizeA)
    {
        C[sizeC] = A[iA];
        iA++;
        sizeC++;
    }

    printArr(sizeC, C);
}

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    if (m < -10000 || n > 10000 || m >= n)
    {
        // Invalid input (out of range or m >= n)
        return 1;
    }

    int u[n - m + 1];
    genUniverse(m, n, u);

    int sizeA;
    scanf("%d", &sizeA);
    if (0 > sizeA || sizeA > 100)
    {
        // Invalid input (out of range)
        return 1;
    }
    int A[sizeA];
    // call getSet function to get the set A
    getSet(&sizeA, A, m, n);

    int sizeB;
    scanf("%d", &sizeB);
    if (0 > sizeB || sizeB > 100)
    {
        // Invalid input (out of range)
        return 1;
    }
    int B[sizeB];
    // call getSet function to get the set B
    getSet(&sizeB, B, m, n);

    printArr(sizeA, A);
    printArr(sizeB, B);

    // Union
    Union(sizeA, sizeB, A, B);

    // // Intersection
    Intersection(sizeA, sizeB, A, B);

    // Difference (A-B)
    Difference(sizeA, sizeB, A, B);

    // Difference (B-A)
    Difference(sizeB, sizeA, B, A);

    // Complement (U-A)
    Difference(n - m + 1, sizeA, u, A);

    // Complement (U-B)
    Difference(n - m + 1, sizeB, u, B);

    return 0;
}