/*In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 
leetcode solution for c*/
#include <stdlib.h>

// Find with path compression
int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

// Union function
int unionSet(int parent[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);

    if (px == py)
        return 0; // cycle detected

    parent[px] = py;
    return 1;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));

    // Initialize parent
    for (int i = 1; i <= edgesSize; i++)
        parent[i] = i;

    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        if (!unionSet(parent, edges[i][0], edges[i][1])) {
            result[0] = edges[i][0];
            result[1] = edges[i][1];
        }
    }

    *returnSize = 2;
    return result;
}