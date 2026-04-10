/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 101

// Min function
int min(int a, int b) {
    return (a < b) ? a : b;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    
    int graph[MAX][MAX];

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Fill edges
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }

    int dist[MAX];
    int visited[MAX] = {0};

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[k] = 0;

    // Dijkstra (simple O(n^2))
    for (int i = 1; i <= n; i++) {
        int u = -1;

        // Find min distance node
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = 1;

        // Relax edges
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && dist[u] != INT_MAX) {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }

    // Find maximum distance
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}