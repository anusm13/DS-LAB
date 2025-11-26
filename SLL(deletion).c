#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

int count() {
    struct node *temp = head;
    int i = 0;
    while (temp != NULL) {
        temp = temp->next;
        i++;
    }
    return i;
}

struct node* create(int value) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void insert_begin(int value) {
    struct node *newnode = create(value);
    newnode->next = head;
    head = newnode;
}

void delete_begin() {
    struct node *temp;
    if (head == NULL) {
        printf("Deletion is not possible\n");
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end() {
    struct node *temp1, *temp2;
    if (head == NULL) {
        printf("Deletion is not possible\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp1 = head;
    while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    free(temp1);
}

void delete_pos(int pos) {
    struct node *temp1, *temp2;
    int i = count(), c = 1;

    if (pos == 1) {
        delete_begin();
        return;
    }
    if (pos > i) {
        printf("Deletion is not possible\n");
        return;
    }

    temp1 = head;
    while (c < pos) {
        temp2 = temp1;
        temp1 = temp1->next;
        c++;
    }

    temp2->next = temp1->next;
    free(temp1);
}

void delete_spec_value(int key) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct node *temp1 = head, *temp2 = NULL;

    if (temp1->data == key) {
        head = temp1->next;
        free(temp1);
        printf("Element %d deleted.\n", key);
        return;
    }

    while (temp1 != NULL && temp1->data != key) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (temp1 == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    temp2->next = temp1->next;
    free(temp1);
    printf("Element %d deleted.\n", key);
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void main() {
    int ch, pos, value, key;
    do {
        printf("\n1. Insert begin\n2. Delete begin\n3. Delete end\n4. Delete position\n5. Delete key\n6. Display\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar(); // **ONLY this line added to fix menu issue**

        switch(ch) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_begin(value);
                break;
            case 2:
                delete_begin();
                break;
            case 3:
                delete_end();
                break;
            case 4:
                printf("Enter position you want to delete: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 5:
                printf("Enter the key value: ");
                scanf("%d", &key);
                delete_spec_value(key);
                break;
            case 6:
                display();
                break;
            case 7:
                break;
            default:
                printf("Your choice is wrong!..\n");
        }
    } while (ch != 7);
}
