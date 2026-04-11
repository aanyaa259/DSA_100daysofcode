/*here are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.*/
#include <limits.h>
#include <stdlib.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    
    int* dist = (int*)malloc(n * sizeof(int));
    
    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax edges k+1 times
    for (int i = 0; i <= k; i++) {
        int* temp = (int*)malloc(n * sizeof(int));
        
        // Copy current distances
        for (int j = 0; j < n; j++) {
            temp[j] = dist[j];
        }

        // Relax all edges
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int cost = flights[j][2];

            if (dist[u] != INT_MAX && dist[u] + cost < temp[v]) {
                temp[v] = dist[u] + cost;
            }
        }

        // Update dist
        for (int j = 0; j < n; j++) {
            dist[j] = temp[j];
        }

        free(temp);
    }

    int ans = dist[dst];
    free(dist);

    return (ans == INT_MAX) ? -1 : ans;
}