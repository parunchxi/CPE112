// Parunchai Kaewkhampa 66070503434
// Assignment 2.4 : Multiplication Matrix

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
void printMatrix(MATRIX_T *matrix);
void freeMatrix(MATRIX_T *matrix);
MATRIX_T *multiplyMatrix(MATRIX_T *matrix1, MATRIX_T *matrix2);

int main(void)
{
    // Input row and column of matrix 1
    int row1, col1;
    scanf("%d %d", &row1, &col1);
    if (row1 < 1 || row1 > 10 || col1 < 1 || col1 > 10)
    {
        // Invalid input (out of range)
        return 1;
    }
    // Input matrix 1
    MATRIX_T *matrix1 = initMatrix(row1, col1);
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &matrix1->arr[i][j]);
            if (matrix1->arr[i][j] < -1000 || matrix1->arr[i][j] > 1000)
            {
                // Invalid input (out of range)
                return 1;
            }
        }
    }
    // Input row and column of matrix 2
    int row2, col2;
    scanf("%d %d", &row2, &col2);
    if (row2 < 1 || row2 > 10 || col2 < 1 || col2 > 10)
    {
        // Invalid input (out of range)
        return 1;
    }
    // Input matrix 2
    MATRIX_T *matrix2 = initMatrix(row2, col2);
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            scanf("%d", &matrix2->arr[i][j]);
            if (matrix2->arr[i][j] < -1000 || matrix2->arr[i][j] > 1000)
            {
                // Invalid input (out of range)
                return 1;
            }
        }
    }

    // Multiply matrix 1 and matrix 2
    MATRIX_T *matrix = multiplyMatrix(matrix1, matrix2);
    if (matrix == NULL)
    {
        printf("Not Compatible\n");
        return 1;
    }

    // Print result
    printMatrix(matrix);

    // Free matrix
    freeMatrix(matrix1);
    freeMatrix(matrix2);
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

void printMatrix(MATRIX_T *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            printf("%d ", matrix->arr[i][j]);
        }
        printf("\n");
    }
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

MATRIX_T *multiplyMatrix(MATRIX_T *matrix1, MATRIX_T *matrix2)
{
    if (matrix1->col != matrix2->row)
    {
        return NULL;
    }
    MATRIX_T *matrix = initMatrix(matrix1->row, matrix2->col);
    for (int i = 0; i < matrix1->row; i++)
    {
        for (int j = 0; j < matrix2->col; j++)
        {
            int sum = 0;
            for (int k = 0; k < matrix1->col; k++)
            {
                sum += matrix1->arr[i][k] * matrix2->arr[k][j];
            }
            matrix->arr[i][j] = sum;
        }
    }
    return matrix;
}