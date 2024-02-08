// Parunchai Kaewkhampa 66070503434
// Lab 2.7 : Dictionary

#include <stdio.h>
#include <string.h>

struct dict
{
    char value[100];
    char key[100];
};

void editdict(struct dict *dic, int size, char *editKey, char *editValue);
void printdict(struct dict *dic, int size);

int main()
{
    // Input dictionary
    int size;
    scanf("%d", &size);
    struct dict dic[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%s %s", dic[i].key, dic[i].value);
    }

    // Input edit
    char editKey[100], editValue[100];
    scanf("%s %s", editKey, editValue);
    // Edit dictionary
    editdict(dic, size, editKey, editValue);

    // Print dictionary
    printdict(dic, size);

    return 0;
}

void editdict(struct dict *dic, int size, char *editKey, char *editValue)
{
    int change = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(dic[i].key, editKey) == 0)
        {
            strcpy(dic[i].value, editValue);
            change = 1;
        }
    }
    if (change == 0)
    {
        printf("No change\n");
    }
}

void printdict(struct dict *dic, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s : %s\n", dic[i].key, dic[i].value);
    }
}