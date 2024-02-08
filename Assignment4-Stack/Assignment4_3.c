// Parunchai Kaewkhampa 66070503434
// Assignment 4.3 : Parenthesis Checker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stack
{
    char data;
    struct stack *next;
} stack;

void push(stack **top, char value);
char pop(stack **top);
bool isEmpty(stack *top);
bool isMatchBrackets(char open, char close);
bool isBalanced(char word[]);

int main(void)
{
    char word[1000];
    scanf("%s", word);
    if (isBalanced(word))
    {
        printf("The string is balanced\n");
    }
    else
    {
        printf("The string is not balanced\n");
    }
    return 0;
}

bool isBalanced(char word[])
{
    stack *top = NULL;
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == '(' || word[i] == '{' || word[i] == '[')
        {
            push(&top, word[i]);
        }
        else if (word[i] == ')' || word[i] == '}' || word[i] == ']')
        {
            if (isEmpty(top))
            {
                return false;
            }
            if (!isMatchBrackets(pop(&top), word[i]))
            {
                return false;
            }
        }
    }
    return isEmpty(top);
}

bool isMatchBrackets(char open, char close)
{
    if (open == '(' && close == ')')
    {
        return true;
    }
    else if (open == '{' && close == '}')
    {
        return true;
    }
    else if (open == '[' && close == ']')
    {
        return true;
    }
    return false;
}

void push(stack **top, char value)
{
    stack *new = (stack *)malloc(sizeof(stack));
    new->data = value;
    new->next = *top;
    *top = new;
}

char pop(stack **top)
{
    if (isEmpty(*top))
    {
        return '\0';
    }
    stack *temp = *top;
    *top = (*top)->next;
    char value = temp->data;
    free(temp);
    return value;
}

bool isEmpty(stack *top)
{
    return (top == NULL);
}