#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;
void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i = 0, j = 0;
    char ch;

    printf("Enter infix expression:\n");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0')
    {
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression:\n");
    printf("%s\n", postfix);

    return 0;
}

