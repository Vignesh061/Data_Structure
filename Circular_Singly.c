#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Circular Singly Linked List Insertion at Front
void InsertFol() {
    struct node* new, *temp;
    int element;
    new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory is not allocated\n");
        return;
    }

    printf("Enter the element to be inserted in front of the list: ");
    scanf("%d", &element);
    new->data = element;

    if (head == NULL) {
        head = new;
        new->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new;
        new->next = head;
        head = new;
    }
}

// Circular Singly Linked List Insertion at Last Position
void InsertEol() {
    struct node* new, *temp;
    int element;
    new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory is not allocated\n");
        return;
    }

    printf("Enter the element to be inserted at the end of the list: ");
    scanf("%d", &element);
    new->data = element;

    if (head == NULL) {
        head = new;
        new->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new;
        new->next = head;
    }
}

// Circular Singly Linked List Deletion at Front
void DeleteFol() {
    struct node* temp, *last;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        last = head;
        while (last->next != head) {
            last = last->next;
        }
        temp = head;
        last->next = head->next;
        head = head->next;
        free(temp);
    }
}

// Circular Singly Linked List Deletion at Last Position
void DeleteEol() {
    struct node* temp, *prev;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
}

// Circular Singly Linked List Display
void display() {
    struct node* temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\nEnter Choice:\n1. Insert at Front\n2. Insert at End\n3. Delete at Front\n4. Delete at End\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            InsertFol();
            display();
            break;
        case 2:
            InsertEol();
            display();
            break;
        case 3:
            DeleteFol();
            display();
            break;
        case 4:
            DeleteEol();
            display();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
