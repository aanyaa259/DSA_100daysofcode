/*In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.


*/
#include <stdlib.h>

// Comparator for sorting
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place m balls with at least 'dist' force
int canPlace(int* position, int n, int m, int dist) {
    int count = 1;
    int last = position[0];

    for (int i = 1; i < n; i++) {
        if (position[i] - last >= dist) {
            count++;
            last = position[i];
        }
        if (count >= m)
            return 1;
    }
    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    // Step 1: Sort positions
    qsort(position, positionSize, sizeof(int), cmp);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int ans = 0;

    // Step 2: Binary search on answer
    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            ans = mid;        // valid → try larger distance
            low = mid + 1;
        } else {
            high = mid - 1;   // invalid → reduce distance
        }
    }

    return ans;
}