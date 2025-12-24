#include<stdio.h>
#include <ctype.h>
int stack[40];
int top = -1;
void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *ptr;
    int n1,n2,n3,num;
    printf("Enter the expression: ");
    scanf("%s",exp);
    ptr = exp;
    while(*ptr != '\0')
    {
    if(isdigit(*ptr ))
    {
    num = *ptr - 48;
    push(num);
    }
    else
    {
    n1 = pop();
    n2 = pop();
    switch(*ptr )
    {
    case '+':
    {
    n3 = n1 + n2;
    break;
    }
    case '-':
    {
    n3 = n2 - n1;
    break;
    }
    case '*':
    {
    n3 = n1 * n2;
    break;
    }
    case '/':
    {
    n3 = n2 / n1;
    break;
    }
    }
    push(n3);
    }
    ptr++;
    }
    printf("\nThe result of expression %s %d\n\n", exp, pop());
    return 0;
}

