// Parunchai Kaewkhampa 66070503434
// Lab 5.3 : Secret Code Only You and I Know

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct character
{
    char name;
    int priority;
    struct character *next;
} CHARACTER;

int isVowel(char c);
int priority(char c);
void insert(CHARACTER **head, char c);
void print(CHARACTER *head);

int main(void)
{
    char input[1000];
    fgets(input, 1000, stdin);
    input[strlen(input) - 1] = '\0';
    CHARACTER *head = NULL;
    for (int i = 0; i < strlen(input); i++)
    {
        insert(&head, input[i]);
    }
    print(head);
    return 0;
}

void insert(CHARACTER **head, char c)
{
    CHARACTER *newCharacter = (CHARACTER *)malloc(sizeof(CHARACTER));
    if (newCharacter == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newCharacter->name = c;
    newCharacter->priority = priority(c);
    newCharacter->next = NULL;
    if (*head == NULL)
    {
        *head = newCharacter;
    }
    else
    {
        CHARACTER *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newCharacter;
    }
}

void print(CHARACTER *head)
{
    CHARACTER *current = head;
    for (int i = 3; i > 0; i--)
    {
        while (current != NULL)
        {
            if (current->priority == i)
            {
                printf("%c", current->name);
            }
            current = current->next;
        }
        current = head;
    }
    printf("\n");
}

int isVowel(char c)
{
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int priority(char c)
{
    if (isVowel(c))
    {
        return 3;
    }
    else if (isalpha(c))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
