// Parunchai Kaewkhampa 66070503434
// Assignment 3.2 : Circular table

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *new(int data);
void insert(node **head, int data);
node *findWinner(node **head, int step);

int main(void)
{
    // Head of the linked list
    node *head = NULL;
    // Input Size & Step
    int size, step;
    scanf("%d %d", &size, &step);
    if (1 > size || size > 100 || 1 > step || step > 100)
    {
        // Invalid Input (Out of range)
        return 1;
    }
    // Input List
    for (int i = 0; i < size; i++)
    {
        int a;
        scanf("%d", &a);
        if (0 > a || a > 10000)
        {
            // Invalid Input (Out of range)
            return 1;
        }
        insert(&head, a);
    }
    // Print Winner
    node *winner = findWinner(&head, step);
    printf("%d", winner->data);

    // Free winner
    free(winner);

    return 0;
}

node *new(int data)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        // Memory allocation failed
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(node **head, int data)
{
    node *newNode = new (data);
    if (*head == NULL)
    {
        // Empty list
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        node *current = *head;
        while (current->next != *head)
        {
            // Find the last node
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

node *findWinner(node **head, int step)
{
    // Last man standing
    if (*head == NULL)
    {
        // Empty list
        return NULL;
    }
    else if ((*head)->next == *head)
    {
        // Only one node (Winner)
        return *head;
    }

    // Find the node to be removed
    node *prev = *head;
    for (int i = 1; i < step - 1; i++)
    {
        prev = prev->next;
    }

    // Remove the node and update head
    node *next = prev->next->next;
    free(prev->next);
    prev->next = next;

    // Recursively find the winner in the updated list
    return findWinner(&next, step);
}