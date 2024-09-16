#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *pre, *next;
};

struct node *head = NULL;

// Function prototypes
void insertFront();
void insertEnd();
void insertMiddle();
void deleteFront();
void deleteEnd();
void deleteMiddle();
void display();

// Insertion at the front
void insertFront() {
    int element;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    newNode->data = element;
    newNode->pre = NULL;
    newNode->next = head;
    if (head != NULL)
        head->pre = newNode;
    head = newNode;
}

// Insertion at the end
void insertEnd() {
    int element;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    newNode->data = element;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->pre = NULL;
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->pre = temp;
}

// Insertion at a specified position
void insertMiddle() {
    int element, position, i = 1;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position == 1) {
        insertFront();
        return;
    }

    struct node *temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->data = element;
    newNode->next = temp->next;
    newNode->pre = temp;
    if (temp->next != NULL)
        temp->next->pre = newNode;
    temp->next = newNode;
}

// Deletion from the front
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->pre = NULL;
    free(temp);
}

// Deletion from the end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    if (head->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;
    temp->pre->next = NULL;
    free(temp);
}

// Deletion from the middle
void deleteMiddle() {
    int position, i = 1;
    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position == 1) {
        deleteFront();
        return;
    }

    struct node *temp = head;
    for (i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->pre != NULL)
        temp->pre->next = temp->next;
    if (temp->next != NULL)
        temp->next->pre = temp->pre;
    free(temp);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertFront();
    insertFront();
    insertFront();
    printf("List after inserting at front:\n");
    display();

    insertEnd();
    printf("List after inserting at end:\n");
    display();

    insertMiddle();
    printf("List after inserting at middle:\n");
    display();

    deleteFront();
    printf("List after deleting from front:\n");
    display();

    deleteEnd();
    printf("List after deleting from end:\n");
    display();

    deleteMiddle();
    printf("List after deleting from middle:\n");
    display();
    return 0;
}
