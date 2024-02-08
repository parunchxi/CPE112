// Parunchai Kaewkhampa 66070503434
// Assignment 2.5 : Spiral Array Printer

#include <stdio.h>
#include <stdlib.h>

typedef struct MATRIX
{
    int row;
    int col;
    int **arr;
} MATRIX_T;

MATRIX_T *initMatrix(int row, int col);
void assignMatrix(MATRIX_T *matrix, int row, int col, int val);
void freeMatrix(MATRIX_T *matrix);
void printSpiral(MATRIX_T *matrix);

int main(void)
{
    // Input row and column
    int row, col;
    scanf("%d %d", &row, &col);
    if (row < 1 || col < 1)
    {
        // Invalid input (out of range)
        return 1;
    }

    // Input matrix
    MATRIX_T *matrix = initMatrix(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix->arr[i][j]);
        }
    }

    // Print spiral
    printSpiral(matrix);

    // Free matrix
    freeMatrix(matrix);

    return 0;
}

MATRIX_T *initMatrix(int row, int col)
{
    MATRIX_T *matrix = (MATRIX_T *)malloc(sizeof(MATRIX_T));
    matrix->row = row;
    matrix->col = col;
    matrix->arr = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix->arr[i] = (int *)malloc(col * sizeof(int));
    }
    return matrix;
}

void assignMatrix(MATRIX_T *matrix, int row, int col, int val)
{
    matrix->arr[row][col] = val;
}

void freeMatrix(MATRIX_T *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    free(matrix);
}

void printSpiral(MATRIX_T *matrix)
{
    int row = matrix->row;
    int col = matrix->col;
    int i, j, k, l;
    int count = 0;
    int total = row * col;
    int *arr = (int *)malloc(total * sizeof(int));

    for (i = 0, j = 0, k = row - 1, l = col - 1; count < total; i++, j++, k--, l--)
    {
        // Top
        for (int m = j; m <= l && count < total; m++)
        {
            arr[count++] = matrix->arr[i][m];
        }
        // Right
        for (int m = i + 1; m <= k && count < total; m++)
        {
            arr[count++] = matrix->arr[m][l];
        }
        // Bottom
        for (int m = l - 1; m >= j && count < total; m--)
        {
            arr[count++] = matrix->arr[k][m];
        }
        // Left
        for (int m = k - 1; m > i && count < total; m--)
        {
            arr[count++] = matrix->arr[m][j];
        }
    }

    for (int i = 0; i < total; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}