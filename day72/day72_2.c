/*Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from 
city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.
*/
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXN 20

int n;
int cost[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

// DP function
int tsp(int mask, int pos) {
    // If all cities visited, return to start
    if (mask == (1 << n) - 1)
        return cost[pos][0];

    // If already computed
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // Try all cities
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] +
                         tsp(mask | (1 << city), city);
            if (newAns < ans)
                ans = newAns;
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    n = 4;

    int input[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Copy input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = input[i][j];

    memset(dp, -1, sizeof(dp));

    int result = tsp(1, 0); // start from city 0

    printf("Minimum cost: %d\n", result);

    return 0;
}