//          Breadth First Search (BFS)


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int adj[MAX][MAX];
int n;

void enqueue(int v) {
    if(rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) {
        front = 0;
    }
    queue[++rear] = v;
}

int dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void BFS(int start) {
    enqueue(start);
    visited[start] = 1;

    while(front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for(int i = 0; i < n; i++) {
            if(adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("BFS Traversal starting from vertex 0:\n");
    BFS(0);

    return 0;
}
