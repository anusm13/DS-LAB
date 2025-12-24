#include <stdio.h>
#include <string.h>

#define SIZE 10

char stack[SIZE];
int top = -1;

int isFull()
{
    return (top == SIZE - 1);
}

int isEmpty()
{
    return (top == -1);
}

void push(char ch)
{
    if (isFull())
        printf("Stack Overflow\n");
    else
        stack[++top] = ch;
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
        return stack[top--];
}

int main()
{
    char str[50], rev[50];
    int i, len, pushed = 0;

    printf("Enter the string:\n");
    gets(str);

    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        if (!isFull())
        {
            push(str[i]);
            pushed++;
        }
        else
            push(str[i]);
    }

    for (i = 0; i < pushed; i++)
    {
        rev[i] = pop();
    }
    rev[i] = '\0';

    printf("Reversed string is:\n");
    puts(rev);

    return 0;
}
