#include <stdio.h>

#define MAX_NODES 10

// Global variables
int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int numNodes;

// Depth-First Search function
void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
    }

    printf("Starting from which node? ");
    int startNode;
    scanf("%d", &startNode);

    printf("DFS Traversal: ");
    dfs(startNode);

    return 0;
}
