// Parunchai Kaewkhampa 66070503434
// Lab 3.2 Before or After Insertion

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *appendList(node *head, int data);
node *beforeInsertion(node *head, int after, int data);
void afterInsertion(node *head, int before, int data);
void printList(node *head);
void freeList(node *head);

int main(void)
{
    // Number of nodes
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid\n");
        return 1;
    }
    // Head of the linked list
    node *head = NULL;
    // Input data
    int data;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = appendList(head, data);
    }
    // Insertion
    char mode;
    int ref;
    while (scanf("%s", &mode) == 1 && mode != 'E')
    {
        scanf("%d %d", &ref, &data);
        if (mode == 'B')
        {
            head = beforeInsertion(head, ref, data);
        }
        else if (mode == 'A')
        {
            afterInsertion(head, ref, data);
        }
        else
        {
            printf("Invalid\n");
            return 1;
        }
    }

    // Print the linked list
    printList(head);
    // Free the linked list
    freeList(head);

    return 0;
}

node *appendList(node *head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        // Memory allocation failed
        return head;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

node *beforeInsertion(node *head, int after, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        // Memory allocation failed
        return head;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    if (head->data == after)
    {
        newNode->next = head;
        return newNode;
    }
    node *current = head;
    while (current->next != NULL)
    {
        if (current->next->data == after)
        {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    }
    return head;
}

void afterInsertion(node *head, int before, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        // Memory allocation failed
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        return;
    }
    node *current = head;
    while (current != NULL)
    {
        if (current->data == before)
        {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void printList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

void freeList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        node *temp = current;
        current = current->next;
        free(temp);
    }
}