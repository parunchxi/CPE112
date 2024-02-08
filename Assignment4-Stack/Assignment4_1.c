// Parunchai Kaewkhampa 66070503434
// Assignment 4.1 : Ten to X

#include <stdio.h>
#include <stdlib.h>

typedef struct digit
{
    char data;
    struct digit *next;
} digit;

char intToChar(int num);
void newDigit(digit **fptr, char value);
void toBaseX(int n, int x, digit **fptr);
void printBaseX(digit *fptr);
void freeList(digit *fptr);

int main(void)
{
    // Input Decimals and Base to convert
    int n, x;
    scanf("%d", &n);
    if (n < 0)
    {
        printf("invalid\n");
        return 1;
    }
    scanf("%d", &x);
    if (x < 2 || x > 36)
    {
        printf("invalid\n");
        return 1;
    }

    // Convert to Base X
    digit *fptr = NULL;
    toBaseX(n, x, &fptr);

    // Print Base X
    printBaseX(fptr);

    // Free List
    freeList(fptr);

    return 0;
}

char intToChar(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

void newDigit(digit **fptr, char value)
{
    digit *new = (digit *)malloc(sizeof(digit));
    new->data = value;
    new->next = *fptr;
    *fptr = new;
}

void toBaseX(int n, int x, digit **fptr)
{
    while (n > 0)
    {
        newDigit(fptr, intToChar(n % x));
        n /= x;
    }
}

void printBaseX(digit *fptr)
{
    while (fptr != NULL)
    {
        printf("%c", fptr->data);
        fptr = fptr->next;
    }
    printf("\n");
}

void freeList(digit *fptr)
{
    while (fptr != NULL)
    {
        digit *temp = fptr;
        fptr = fptr->next;
        free(temp);
    }
}