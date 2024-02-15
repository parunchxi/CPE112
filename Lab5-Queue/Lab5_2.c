// Parunchai Kaewkhampa 66070503434
// Lab 5.2 : When Will it Be My Turn???

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertq(int *queue, int *FRONT, int *REAR, int size, int value);
void dequeue(int *queue, int *FRONT, int *REAR, int size);
void show(int *queue, int FRONT, int REAR, int size);

int main(void)
{
    // Input size of queue
    int size;
    scanf("%d", &size);
    if (1 > size || size > 10)
    {
        printf("Invalid size\n");
        return 1;
    }
    // Create queue
    int FRONT = -1, REAR = -1;
    int *queue = (int *)malloc(size * sizeof(int));
    if (queue == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    // Menu
    char command[2];
    while (1)
    {
        scanf("%s", &command);
        if (strcmp(command, "I") == 0)
        {
            int value;
            scanf("%d", &value);
            insertq(queue, &FRONT, &REAR, size, value);
        }
        else if (strcmp(command, "D") == 0)
        {
            dequeue(queue, &FRONT, &REAR, size);
        }
        else if (strcmp(command, "S") == 0)
        {
            show(queue, FRONT, REAR, size);
        }
        else if (strcmp(command, "E") == 0)
        {
            free(queue);
            return 0;
        }
        else
        {
            printf("Invalid command\n");
            return 1;
        }
    }
}

void insertq(int *queue, int *FRONT, int *REAR, int size, int value)
{
    if ((*FRONT == 0 && *REAR == size - 1) || (*REAR == *FRONT - 1))
    {
        printf("Queue is full!!\n");
        return;
    }
    if (*FRONT == -1)
    {
        // Queue is empty
        *FRONT = 0;
        *REAR = 0;
    }
    else if (*REAR == size - 1)
    {
        // REAR = last index
        *REAR = 0;
    }
    else
    {
        // Increment REAR
        *REAR = *REAR + 1;
    }
    // Insert value
    queue[*REAR] = value;
}

void dequeue(int *queue, int *FRONT, int *REAR, int size)
{
    if (*FRONT == -1)
    {
        printf("Queue is empty!!\n");
        return;
    }
    int value = queue[*FRONT];
    if (*FRONT == *REAR)
    {
        // Queue has only one element
        *FRONT = -1;
        *REAR = -1;
    }
    else if (*FRONT == size - 1)
    {
        // FRONT = last index
        *FRONT = 0;
    }
    else
    {
        // Increment FRONT
        *FRONT = *FRONT + 1;
    }
    // Print value
    printf("%d\n", value);
}

void show(int *queue, int FRONT, int REAR, int size)
{
    if (FRONT == -1)
    {
        printf("Queue is empty!!\n");
        return;
    }
    printf("Front: %d\n", FRONT);
    printf("Items: ");
    if (REAR >= FRONT)
    {
        for (int i = FRONT; i <= REAR; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for (int i = FRONT; i < size; i++)
        {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= REAR; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
    printf("Rear: %d\n", REAR);
}