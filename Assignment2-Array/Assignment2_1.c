// Parunchai Kaewkhampa 66070503434
// Assignment 2.1 : Grading

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char name[100];
    float score;
} STUDENT_T;

float findMean(STUDENT_T *student, int size);
float findSD(STUDENT_T *student, int size, float mean);
char *findMax(STUDENT_T *student, int size);
char *findMin(STUDENT_T *student, int size);

int main(void)
{
    // Input number of student
    int size;
    scanf("%d", &size);
    if (1 > size || size > 100)
    {
        // Invalid input (out of range)
        return 1;
    }

    // Input student data
    STUDENT_T *student = (STUDENT_T *)malloc(size * sizeof(STUDENT_T));
    if (student == NULL)
    {
        // Memory allocation failed
        return 1;
    }
    for (int i = 0; i < size; i++)
    {
        scanf("%s %f", student[i].name, &student[i].score);
        if (1 > strlen(student[i].name) || strlen(student[i].name) > 100 || 0 > student[i].score || student[i].score > 100)
        {
            // Invalid input
            return 1;
        }
    }

    // Mean, SD, name of max, name of min
    float mean = findMean(student, size);
    float sd = findSD(student, size, mean);
    char *max = findMax(student, size);
    char *min = findMin(student, size);

    printf("%.2f %.2f %s %s\n", mean, sd, max, min);
}

float findMean(STUDENT_T *student, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += student[i].score;
    }
    return sum / size;
}

float findSD(STUDENT_T *student, int size, float mean)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += pow(student[i].score - mean, 2);
    }
    return sqrt(sum / size);
}

char *findMax(STUDENT_T *student, int size)
{
    float max = student[0].score;
    int maxIdx = 0;
    for (int i = 1; i < size; i++)
    {
        if (student[i].score > max)
        {
            max = student[i].score;
            maxIdx = i;
        }
    }
    return student[maxIdx].name;
}

char *findMin(STUDENT_T *student, int size)
{
    float min = student[0].score;
    int minIdx = 0;
    for (int i = 1; i < size; i++)
    {
        if (student[i].score < min)
        {
            min = student[i].score;
            minIdx = i;
        }
    }
    return student[minIdx].name;
}