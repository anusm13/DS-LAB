#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create(int value) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Function to insert at beginning
struct node *insert_beg(struct node *head, int value) {
    struct node *newnode = create(value);
    newnode->next = head;
    head = newnode;
    return head;
}

// Function to print list
void display(struct node *head) {
    struct node *current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Reverse list function
struct node *reverse_list(struct node *head) {
    struct node *prev = NULL, *current = head, *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Sort list (bubble sort)
struct node *sort_list(struct node *head) {
    int swap;
    struct node *ptr1;
    struct node *lptr = NULL;
    if(head == NULL)
        return NULL;

    do {
        swap = 0;
        ptr1 = head;
        while(ptr1->next != lptr) {
            if(ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swap);
    return head;
}

// Concatenate lists
struct node* concat_lists(struct node *head1, struct node *head2) {
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;

    struct node *current = head1;
    while(current->next != NULL)
        current = current->next;
    current->next = head2;
    return head1;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    int m, n, val;

    printf("Enter no. of nodes in list1 and list2\n");
    scanf("%d %d", &m, &n);

    printf("Enter values for List 1:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &val);
        head1 = insert_beg(head1, val);
    }
    printf("List 1: ");
    display(head1);

    printf("Enter values for List 2:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        head2 = insert_beg(head2, val);  // Corrected list insertion
    }
    printf("List 2: ");
    display(head2);

    head1 = reverse_list(head1);
    printf("Reversed List 1: ");
    display(head1);

    head2 = sort_list(head2);
    printf("Sorted List 2: ");
    display(head2);

    struct node *concat_head = concat_lists(head1, head2);
    printf("Concatenated List: ");
    display(concat_head);

    return 0;
}
