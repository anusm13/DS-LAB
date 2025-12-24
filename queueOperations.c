#include <stdio.h>
#include <stdlib.h>

#define max 4

int queue_array[max];
int rear = -1;
int front = -1;

void insert()
{
    int add_item;

    if (rear == max - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        printf("Enter an element to insert: ");
        scanf("%d", &add_item);

        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void delete()
{
    int val;

    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        val = queue_array[front];
        front = front + 1;
        printf("Deleted element: %d\n", val);
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", queue_array[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
