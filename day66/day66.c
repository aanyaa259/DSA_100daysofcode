/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int** adj, int* adjSize, bool* visited, bool* recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        // If not visited, recurse
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack)) {
                return true;
            }
        }
        // If already in recursion stack → cycle
        else if (recStack[neighbor]) {
            return true;
        }
    }

    // Remove from recursion stack
    recStack[node] = false;
    return false;
}

bool hasCycle(int V, int** adj, int* adjSize) {
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                free(visited);
                free(recStack);
                return true;
            }
        }
    }

    free(visited);
    free(recStack);
    return false;
}

// Driver code
int main() {
    int V = 4;

    // Example graph:
    // 0 → 1 → 2 → 3 → 1 (cycle)
    int adjSize[] = {1, 1, 1, 1};

    int* adj[4];
    adj[0] = (int[]){1};
    adj[1] = (int[]){2};
    adj[2] = (int[]){3};
    adj[3] = (int[]){1};

    if (hasCycle(V, adj, adjSize)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}