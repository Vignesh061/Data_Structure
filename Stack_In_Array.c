#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the stack

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Function prototypes
void initialize(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);

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
void initialize(Stack *s) {
    s->top = -1; // Empty stack
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push data onto the stack
void push(Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack is full! Cannot push %d\n", data);
    } else {
        s->arr[++s->top] = data;
        printf("Pushed %d\n", data);
    }
}

// Pop data from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop\n");
        return -1;
    } else {
        return s->arr[s->top--];
    }
}

// Peek at the top element of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;
    } else {
        return s->arr[s->top];
    }
}

// Display all elements of the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}
