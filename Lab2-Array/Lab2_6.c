// Parunchai Kaewkhampa 66070503434
// Lab 2.6 : Sum of Diagonal Matrix

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

int main(void)
{
    // Input row and column
    int row, col;
    scanf("%d %d", &row, &col);
    if (row != col)
    {
        printf("ERROR");
        return 1;
    }
    // Input matrix
    MATRIX_T *matrix = initMatrix(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; ++j)
        {
            int val;
            scanf("%d", &val);
            assignMatrix(matrix, i, j, val);
        }
    }

    // Sum of diagonal
    int primary = 0, secondary = 0;
    for (int i = 0; i < row; i++)
    {
        primary += matrix->arr[i][i];
        secondary += matrix->arr[i][row - i - 1];
    }

    // Print result
    printf("Primary: %d\n", primary);
    printf("Secondary: %d\n", secondary);

    // Free memory
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