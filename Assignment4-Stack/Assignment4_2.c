// Parunchai Kaewkhampa 66070503434
// Assignment 4.2 : Palindrome Checker

#include <stdio.h>
#include <string.h>

int isPalindrome(char input[], int left, int right);

int main(void)
{
    char input[255];
    scanf("%s", input);
    int left = 0, right = strlen(input) - 1;
    if (isPalindrome(input, left, right))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}

int isPalindrome(char input[], int left, int right)
{
    if (left >= right)
    {
        return 1;
    }
    if (input[left] != input[right])
    {
        return 0;
    }
    return isPalindrome(input, left + 1, right - 1);
}
