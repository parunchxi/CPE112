// Parunchai Kaewkhampa 66070503434
// Assignment 3.3: Reverse Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *new(int val);
void insert(ListNode **head, int val);
void reverse(ListNode **head, int start, int end);
void printList(ListNode *head);
void freeList(ListNode *head);

int main(void)
{
    // Head of the linked list
    ListNode *head = NULL;
    // Input List
    char input[7];
    while (scanf("%s", input) == 1 && strcmp(input, "END") != 0)
    {
        int x = atoi(input);
        if (-10000 > x || x > 10000)
        {
            // Invalid Input (Out of range)
            return 1;
        }
        insert(&head, x);
    }
    // Input start & end
    int start, end;
    scanf("%d %d", &start, &end);
    if (start > end)
    {
        // Invalid Input (start > end)
        return 1;
    }

    // Reverse List only from start to end
    reverse(&head, start, end);

    // Print List
    printList(head);

    // Free List
    freeList(head);

    return 0;
}

ListNode *new(int val)
{
    ListNode *newNode = malloc(sizeof(ListNode));
    if (newNode == NULL)
    {
        // Memory allocation failed
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insert(ListNode **head, int val)
{
    ListNode *newNode = new (val);
    // Add new node to the list
    if (*head == NULL)
    {
        // If list is empty
        *head = newNode;
    }
    else
    {
        ListNode *current = *head;
        while (current->next != NULL)
        {
            // loop until the last node.
            current = current->next;
        }
        current->next = newNode;
    }
}

void reverse(ListNode **head, int start, int end)
{
    if (*head == NULL || start == end)
    {
        // Empty list or no need to reverse
        return;
    }

    // Initialize pointers to traverse the list
    ListNode *prev = NULL;
    ListNode *current = *head;
    ListNode *next = NULL;

    // Traverse to the starting position
    int i;
    for (i = 1; i < start; i++)
    {
        prev = current;
        current = current->next;
    }

    // Reverse the sublist from start to end
    ListNode *sublist_prev = prev;
    ListNode *sublist_start = current;
    for (; i <= end && current != NULL; i++)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Connect the reversed sublist back to the original list
    if (sublist_prev != NULL)
    {
        sublist_prev->next = prev;
    }
    else
    {
        *head = prev;
    }
    sublist_start->next = current;
}

void printList(ListNode *head)
{
    // Print the list
    if (head == NULL)
    {
        // Empty list
        return;
    }
    ListNode *current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

void freeList(ListNode *head)
{
    if (head == NULL)
    {
        // Empty list
        return;
    }
    ListNode *current = head;
    ListNode *next = NULL;
    do
    {
        next = current->next;
        free(current);
        current = next;
    } while (current != NULL);
}
