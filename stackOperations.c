#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", x);
    }
    else
    {
        top++;
        stack[top] = x;
        printf("Pushed %d into stack\n", x);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Cannot pop\n");
    }
    else
    {
        printf("Popped %d from stack\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void peek()
{
    if (top >= 0)
    {
        printf("Peeked element: %d\n", stack[top]);
    }
    else
    {
        printf("Stack is empty. Cannot peek\n");
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n*** MENU ***\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
