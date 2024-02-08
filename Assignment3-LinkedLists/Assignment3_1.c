// Parunchai Kaewkhampa 66070503434
// Assignment 3.1 : It's Sorting Time

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int ID;
    int score;
    struct node *next;
} node;

node *new(int ID, int score);
void insert(node **head, int ID, int score);
void sortByID(node **head);
void sortByScore(node **head);
void printScore(node *head);
void freeList(node *head);

int main(void)
{
    // Head of the linked list
    node *head = NULL;
    // Input Size
    int size; // size: number of student
    scanf("%d", &size);
    if (1 > size || size > 100)
    {
        // Invalid Input (Out of range)
        return 1;
    }
    // Input List
    for (int i = 0; i < size; i++)
    {
        int n, m; // n: id, m: score
        scanf("%d %d", &n, &m);
        if (1000 > n || n > 9999 || 0 > m || m > 100)
        {
            // Invalid Input (Out of range)
            return 1;
        }
        insert(&head, n, m);
    }
    // Input mode
    int mode;
    scanf("%d", &mode);
    if (mode != 0 && mode != 1)
    {
        // Invalid Input (Out of range)
        return 1;
    }

    // Print List
    if (mode == 0)
    {
        // Sort by ID
        sortByID(&head);
        printScore(head);
    }
    else
    {
        // Sort by Score
        sortByScore(&head);
        printScore(head);
    }

    // Free List
    freeList(head);
    return 0;
}

node *new(int ID, int score)
{
    // Create new node
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        // Memory allocation failed
        exit(1);
    }
    // Assign value to new node
    newNode->ID = ID;
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void insert(node **head, int ID, int score)
{
    node *newNode = new (ID, score);
    // Add new node to the list
    if (*head == NULL)
    {
        // If list is empty
        *head = newNode;
    }
    else
    {
        node *current = *head;
        while (current->next != NULL)
        {
            // loop until the last node.
            current = current->next;
        }
        current->next = newNode;
    }
}

void sortByID(node **head)
{
    node *current = *head;
    node *next = NULL;
    int tempID, tempScore;
    while (current != NULL)
    {
        next = current->next;
        while (next != NULL)
        {
            if (current->ID > next->ID)
            {
                // Swap ID
                tempID = current->ID;
                current->ID = next->ID;
                next->ID = tempID;
                // Swap Score
                tempScore = current->score;
                current->score = next->score;
                next->score = tempScore;
            }
            next = next->next;
        }
        current = current->next;
    }
}

void sortByScore(node **head)
{
    node *current = *head;
    node *next = NULL;
    int tempID, tempScore;
    while (current != NULL)
    {
        next = current->next;
        while (next != NULL)
        {
            if (current->score > next->score)
            {
                // Swap ID
                tempID = current->ID;
                current->ID = next->ID;
                next->ID = tempID;
                // Swap Score
                tempScore = current->score;
                current->score = next->score;
                next->score = tempScore;
            }
            next = next->next;
        }
        current = current->next;
    }
}

void printScore(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->score);
        current = current->next;
    }
}

void freeList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        node *next = current->next;
        free(current);
        current = next;
    }
}