#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = data;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    int item = queue[front];
    front++;
    return item;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void BFS(int graph[][MAX_SIZE], int vertices, int start) {
    int visited[MAX_SIZE] = {0};
    int i, current;
    
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int vertices, edges, i, j, start;
    int graph[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(graph, vertices, start);

    printf("\n");

    return 0;
}
