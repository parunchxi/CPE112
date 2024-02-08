// Parunchai Kaewkhampa 66070503434
// Lab 3.5 : Circular Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *insert(node *head, int data);
node *delete(node *head, int data);
void printList(node *head);
void freeList(node *head);

int main(void)
{
    node *head = NULL;
    int data;
    char *command = (char *)malloc(sizeof(char) * 4);
    while (scanf("%s", command) == 1)
    {
        if (strcmp(command, "I") == 0)
        {
            scanf("%d", &data);
            head = insert(head, data);
        }
        else if (strcmp(command, "D") == 0)
        {
            scanf("%d", &data);
            head = delete (head, data);
        }
        else if (strcmp(command, "E") == 0)
        {
            break;
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

node *insert(node *head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}

node *delete(node *head, int data)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == data)
    {
        node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        if (current == head)
        {
            free(head);
            return NULL;
        }
        current->next = head->next;
        free(head);
        return current->next;
    }
    node *current = head;
    while (current->next != head)
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
    if (head == NULL)
    {
        printf("Empty\n");
        return;
    }
    node *current = head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void freeList(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *current = head;
    do
    {
        node *temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}