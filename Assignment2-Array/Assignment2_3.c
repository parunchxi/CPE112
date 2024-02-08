// Parunchai Kaewkhampa 66070503434
// Assignment 2.3 : Symmetric Matrix

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
int isSymmetric(MATRIX_T *matrix);
int isSkewSymmetric(MATRIX_T *matrix);

int main(void)
{
    // Input row and column
    int row, col;
    scanf("%d %d", &row, &col);
    if (row < 1 || row > 10000 || col < 1 || col > 10000 || row != col)
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

    // Check if matrix is symmetric
    if (isSymmetric(matrix))
    {
        printf("The matrix is symmetric\n");
    }
    else if (isSkewSymmetric(matrix))
    {
        printf("The matrix is skew-symmetric\n");
    }
    else
    {
        printf("None\n");
    }

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

int isSymmetric(MATRIX_T *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            if (matrix->arr[i][j] != matrix->arr[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int isSkewSymmetric(MATRIX_T *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            if (matrix->arr[i][j] != -matrix->arr[j][i] && i != j)
            {
                return 0;
            }
        }
    }
    return 1;
}