#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int parent[MAX_SIZE];
int rank[MAX_SIZE];

// Initialize the disjoint set
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find the root of the set to which element x belongs
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union of two sets
void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int n; // Number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    makeSet(n);

    int m; // Number of union operations
    printf("Enter the number of union operations: ");
    scanf("%d", &m);

    printf("Enter pairs (x, y) to perform union:\n");
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        unionSet(x, y);
    }

    printf("Parent Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", parent[i]);
    printf("\n");

    return 0;
}
