#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;
} Stack;

// Function prototypes
void initialize(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s, int data);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main() {
    Stack s;
    int choice, value;

    initialize(&s);

    while (1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&s);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}

// Initialize the stack
void initialize(Stack* s) {
    s->top = NULL;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Push data onto the stack
void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    printf("Pushed %d\n", data);
}

// Pop data from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop\n");
        return -1;
    }
    Node* temp = s->top;
    int poppedValue = temp->data;
    s->top = temp->next;
    free(temp);
    return poppedValue;
}

// Peek at the top element of the stack
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;
    }
    return s->top->data;
}

// Display all elements of the stack
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    Node* current = s->top;
    printf("Stack elements: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
