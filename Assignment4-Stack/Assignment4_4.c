// Parunchai Kaewkhampa 66070503434
// Assignment 4.4 : Infix to Postfix

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
int precedence(char operator);
void infixToPostfix(char infix[], char postfix[]);

int main(void)
{
    char infix[1000];
    scanf("%s", infix);
    char postfix[1000];
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    stack *ops = NULL;
    int infixLength = strlen(infix);
    int j = 0;
    // Scan infix from left to right
    for (int i = 0; i < infixLength; i++)
    {
        char cif = infix[i];
        if ((cif >= 'a' && cif <= 'z') || (cif >= 'A' && cif <= 'Z'))
        {
            // Operand
            postfix[j++] = cif;
        }
        else if (cif == '(')
        {
            // Open parenthesis
            push(&ops, cif);
        }
        else if (cif == ')')
        {
            // Close parenthesis
            while (!isEmpty(ops) && ops->data != '(')
            {
                // Pop operators to postfix until '('
                postfix[j++] = pop(&ops);
            }
            pop(&ops); // Remove '('
        }
        else
        {
            // Operator
            while (!isEmpty(ops) && precedence(cif) <= precedence(ops->data))
            {
                // Pop operators to postfix until precedence of current operator is higher than the top of the stack
                postfix[j++] = pop(&ops);
            }
            push(&ops, cif); // Push current operator to stack
        }
    }
    // Pop remaining operators to postfix
    while (!isEmpty(ops))
    {
        postfix[j++] = pop(&ops);
    }
    // Add null terminator
    postfix[j] = '\0';
}

int precedence(char operator)
{
    if (operator== '+' || operator== '-')
        return 1;
    else if (operator== '*' || operator== '/')
        return 2;
    else if (operator== '^')
        return 3;
    else
        return -1;
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
    char value = (*top)->data;
    stack *temp = *top;
    *top = (*top)->next;
    free(temp);
    return value;
}

bool isEmpty(stack *top)
{
    return top == NULL;
}