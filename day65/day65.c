/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int parent, int** adj, int* adjSize, bool* visited) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, adjSize, visited)) {
                return true;
            }
        }
        else if (neighbor != parent) {
            return true; // cycle detected
        }
    }

    return false;
}

int main() {
    int V, E;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Allocate adjacency list
    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int));
    }

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u; // undirected
    }

    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool cycle = false;

    // Check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, adjSize, visited)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}