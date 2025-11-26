#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Global pointer for Stack operations
struct node *stack_top = NULL;

// Global pointers for Queue operations
struct node *queue_front = NULL;
struct node *queue_rear = NULL;

// Push operation for Stack
void push(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = stack_top;
    stack_top = newnode;
    printf("%d pushed to stack.\n", value);
}

// Pop operation for Stack
int pop() {
    if (stack_top == NULL) {
        printf("Stack Underflow: Stack is empty.\n");
        return 0;
    }
    struct node *temp = stack_top;
    int val = temp->data;
    stack_top = stack_top->next;
    free(temp);
    printf("%d popped from stack.\n", val);
    return val;
}

// Peek operation for Stack
int peek_stack() {
    if (stack_top == NULL) {
        printf("Stack is empty. No top element.\n");
        return -1;
    }
    return stack_top->data;
}

// Display Stack
void display_stack() {
    if (stack_top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct node *current = stack_top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Enqueue operation for Queue
void enqueue(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (queue_front == NULL) {
        queue_front = newnode;
        queue_rear = newnode;
    } else {
        queue_rear->next = newnode;
        queue_rear = newnode;
    }
    printf("%d enqueued to queue.\n", value);
}

// Dequeue operation for Queue
int dequeue() {
    if (queue_front == NULL) {
        printf("Queue Underflow: Queue is empty.\n");
        return 0;
    }
    struct node *temp = queue_front;
    int value = temp->data;
    queue_front = queue_front->next;

    if (queue_front == NULL) queue_rear = NULL;

    free(temp);
    printf("%d dequeued from queue.\n", value);
    return value;
}

// Peek operation for Queue
int peek_queue() {
    if (queue_front == NULL) {
        printf("Queue is empty. No front element.\n");
        return -1;
    }
    return queue_front->data;
}

// Display Queue
void display_queue() {
    if (queue_front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct node* current = queue_front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int option, val, del, p;
    do {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Push an element");
        printf("\n 2. Pop an element");
        printf("\n 3. Peek Stack Top");
        printf("\n 4. Display the Stack");
        printf("\n 5. Enqueue an element");
        printf("\n 6. Dequeue an element");
        printf("\n 7. Peek Queue Front");
        printf("\n 8. Display the Queue");
        printf("\n 9. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter number to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                del = pop();
                printf("Popped: %d\n", del);
                break;
            case 3:
                p = peek_stack();
                printf("Top element: %d\n", p);
                break;
            case 4:
                display_stack();
                break;
            case 5:
                printf("Enter number to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 6:
                del = dequeue();
                printf("Dequeued: %d\n", del);
                break;
            case 7:
                p = peek_queue();
                printf("Front element: %d\n", p);
                break;
            case 8:
                display_queue();
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(option != 9);

    return 0;
}
