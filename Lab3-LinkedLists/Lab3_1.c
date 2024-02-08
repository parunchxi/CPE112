// Parunchai Kaewkhampa 66070503434
// Lab 3.1 : Linked List Insertion

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *insertAtHead(node *head, int data);
node *insertAtRear(node *head, int data);
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
    // Mode of insertion
    int mode;
    scanf("%d", &mode);
    if (mode != 1 && mode != 2)
    {
        printf("Invalid\n");
        return 1;
    }
    // Head of the linked list
    node *head = NULL;
    // Insertion
    int data;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        if (mode == 1)
        {
            head = insertAtHead(head, data);
        }
        else
        {
            head = insertAtRear(head, data);
        }
    }

    // Print the linked list
    printList(head);
    // Free the linked list
    freeList(head);

    return 0;
}

node *insertAtHead(node *head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        // Memory allocation failed
        return head;
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

node *insertAtRear(node *head, int data)
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

void PrintList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

void FreeList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        node *temp = current;
        current = current->next;
        free(temp);
    }
}