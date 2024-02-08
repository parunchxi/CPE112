// Parunchai Kaewkhampa 66070503434
// Lab 3.3 : Where to Delete ?

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *appendList(node *head, int data);
node *deleteFirstNode(node *head);
node *deleteLastNode(node *head);
node *deleteNode(node *head, int data);
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
    // Deletion
    char mode;
    while (scanf("%s", &mode) == 1 && mode != 'E')
    {
        if (mode == 'F')
        {
            head = deleteFirstNode(head);
        }
        else if (mode == 'L')
        {
            head = deleteLastNode(head);
        }
        else if (mode == 'N')
        {
            scanf("%d", &data);
            head = deleteNode(head, data);
        }
        else
        {
            printf("Invalid\n");
            return 1;
        }
        if (head == NULL)
        {
            printf("none\n");
            return 0;
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

node *deleteFirstNode(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

node *deleteLastNode(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

node *deleteNode(node *head, int data)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == data)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    node *current = head;
    while (current->next != NULL)
    {
        if (current->next->data == data)
        {
            node *temp = current->next;
            current->next = current->next->next;
            free(temp);
            return head;
        }
        current = current->next;
    }
    return head;
}

void printList(node *head)
{
    int count = 0;
    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
        count++;
    }
    if (count == 0)
    {
        printf("none\n");
    }
    printf("\n");
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