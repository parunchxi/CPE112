// Parunchai Kaewkhampa 66070503434
// Lab 3.4 : Linked List that can Go Back

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

void ADD(node **head, node **tail, int data);
void DEL(node **head, node **tail, int data);
void SCH(node *head, int data);
void printListFromHead(node *head);
void printListFromTail(node *tail);
void freeList(node *head);

int main(void)
{
    node *head = NULL, *tail = NULL;
    int data;
    char *command = (char *)malloc(sizeof(char) * 4);
    while (scanf("%s", command) == 1)
    {
        if (strcmp(command, "ADD") == 0)
        {
            scanf("%d", &data);
            ADD(&head, &tail, data);
        }
        else if (strcmp(command, "DEL") == 0)
        {
            scanf("%d", &data);
            DEL(&head, &tail, data);
        }
        else if (strcmp(command, "SCH") == 0)
        {
            scanf("%d", &data);
            SCH(head, data);
        }
        else if (strcmp(command, "END") == 0)
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
    printListFromHead(head);
    printListFromTail(tail);

    // Free the linked list
    freeList(head);

    return 0;
}

void ADD(node **head, node **tail, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void DEL(node **head, node **tail, int data)
{
    node *current = *head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                *head = current->next;
            }

            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            else
            {
                *tail = current->prev;
            }

            free(current);
            return;
        }
        current = current->next;
    }
}

void SCH(node *head, int data)
{
    node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            // Previous data
            node *prev = current->prev;
            if (prev == NULL)
            {
                printf("NULL ");
            }
            else
            {
                printf("%d ", prev->data);
            }
            // Next data
            node *next = current->next;
            if (next == NULL)
            {
                printf("NULL\n");
            }
            else
            {
                printf("%d\n", next->data);
            }

            return;
        }
        current = current->next;
    }
    printf("none\n");
}

void printListFromHead(node *head)
{
    node *current = head;
    if (current == NULL)
    {
        printf("none\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printListFromTail(node *tail)
{
    node *current = tail;
    if (current == NULL)
    {
        printf("none\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
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