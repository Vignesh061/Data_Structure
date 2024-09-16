#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the queue

// Queue structure
typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Queue;

// Function prototypes
void initialize(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int peek(Queue *q);
void display(Queue *q);
void queueSize(Queue *q);
void isQueueEmpty(Queue *q);

int main() {
    Queue q;
    int choice, value;

    initialize(&q);

    while (1) {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Queue Size");
        printf("\n6. Check if Queue is Empty");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Front value: %d\n", value);
                }
                break;
            case 4:
                display(&q);
                break;
            case 5:
                queueSize(&q);
                break;
            case 6:
                isQueueEmpty(&q);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}

// Initialize the queue
void initialize(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Check if the queue is full
int isFull(Queue *q) {
    return q->size == MAX;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Enqueue data into the queue
void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", data);
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = data;
        q->size++;
        printf("Enqueued %d\n", data);
    }
}

// Dequeue data from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    } else {
        int data = q->arr[q->front];
        q->front = (q->front + 1) % MAX;
        q->size--;
        return data;
    }
}

// Peek at the front element of the queue
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek\n");
        return -1;
    } else {
        return q->arr[q->front];
    }
}

// Display all elements in the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i;
    for (i = 0; i < q->size; i++) {
        printf("%d ", q->arr[(q->front + i) % MAX]);
    }
    printf("\n");
}

// Display the size of the queue
void queueSize(Queue *q) {
    printf("Queue size: %d\n", q->size);
}

// Check if the queue is empty
void isQueueEmpty(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
}
