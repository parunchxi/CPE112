// Parunchai Kaewkhampa 66070503434
// Lab 4.1 Stack Array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void push(node **tptr, int value);
void pop(node **tptr);
void top(node *tptr);
void show(node *tptr);
bool isEmpty(node *tptr);
void freeStack(node *tptr);

int main(void)
{
    node *tptr = NULL;
    char choice;
    while (scanf(" %c", &choice) == 1)
    {
        switch (choice)
        {
        case 'p':
            // Push
            int value;
            scanf("%d", &value);
            push(&tptr, value);
            break;
        case 'o':
            // Pop
            pop(&tptr);
            break;
        case 't':
            // Top
            top(tptr);
            break;
        case 'e':
            // empty
            printf("%d\n", isEmpty(tptr));
            break;
        case 's':
            // Show
            show(tptr);
            break;
        case 'q':
            // Exit
            freeStack(tptr);
            return 0;
        default:
            printf("Invalid choice.\n");
            return 1;
        }
    }
}

void push(node **tptr, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = *tptr;
    *tptr = newNode;
}

void pop(node **tptr)
{
    if (isEmpty(*tptr))
    {
        printf("empty\n");
        return;
    }
    else
    {
        printf("%d\n", (*tptr)->data);
        node *temp = *tptr;
        *tptr = (*tptr)->next;
        free(temp);
    }
}

void top(node *tptr)
{
    if (isEmpty(tptr))
    {
        printf("empty\n");
        return;
    }
    printf("%d\n", tptr->data);
}

void show(node *tptr)
{
    if (isEmpty(tptr))
    {
        printf("empty\n");
        return;
    }
    else
    {
        node *temp = tptr;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

bool isEmpty(node *tptr)
{
    return tptr == NULL;
}

void freeStack(node *tptr)
{
    while (tptr != NULL)
    {
        node *temp = tptr;
        tptr = tptr->next;
        free(temp);
    }
}
