// Parunchai Kaewkhampa 66070503434
// Lab 5.1 Spotify

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music
{
    char name[100];
    char artist[100];
    int time; // in seconds
    struct music *next;
} MUSIC;

MUSIC *getMusic();
void add(MUSIC **head);
void play(MUSIC **head);
void sum(MUSIC *head);

int main(void)
{
    MUSIC *head = NULL;
    char command[10];
    while (1)
    {
        scanf("%s", &command);
        if (strcmp(command, "add") == 0)
        {
            add(&head);
        }
        else if (strcmp(command, "play") == 0)
        {
            play(&head);
        }
        else if (strcmp(command, "sum") == 0)
        {
            sum(head);
            return 0;
        }
        else
        {
            printf("Invalid command\n");
            return 1;
        }
    }
}

MUSIC *getMusic()
{
    MUSIC *newMusic = (MUSIC *)malloc(sizeof(MUSIC));
    if (newMusic == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    getchar();
    fgets(newMusic->name, 100, stdin);
    newMusic->name[strlen(newMusic->name) - 1] = '\0';
    fgets(newMusic->artist, 100, stdin);
    newMusic->artist[strlen(newMusic->artist) - 1] = '\0';
    scanf("%d", &newMusic->time);
    newMusic->next = NULL;
    return newMusic;
}

void add(MUSIC **head)
{
    MUSIC *newMusic = getMusic();
    if (*head == NULL)
    {
        *head = newMusic;
    }
    else
    {
        MUSIC *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newMusic;
    }
}

void play(MUSIC **head)
{
    if (*head == NULL)
    {
        printf("No songs in the playlist\n");
    }
    else
    {
        printf("Now playing: %s by %s\n", (*head)->name, (*head)->artist);
        MUSIC *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void sum(MUSIC *head)
{
    int sum = 0;
    printf("Songs in the playlist:\n");
    while (head != NULL)
    {
        printf("%s by %s %d\n", head->name, head->artist, head->time);
        sum += head->time;
        head = head->next;
    }
    printf("Remaining Time: %d\n", sum);
}