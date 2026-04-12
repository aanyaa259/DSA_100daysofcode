/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.*/
int manhattan(int* p1, int* p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;

    int* key = (int*)malloc(n * sizeof(int));
    int* mstSet = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        key[i] = INT_MAX;
    }

    key[0] = 0;
    int totalCost = 0;

    for(int count = 0; count < n; count++) {

        int u = -1;
        for(int i = 0; i < n; i++) {
            if(!mstSet[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        mstSet[u] = 1;
        totalCost += key[u];

        for(int v = 0; v < n; v++) {
            if(!mstSet[v]) {
                int dist = manhattan(points[u], points[v]);
                if(dist < key[v]) {
                    key[v] = dist;
                }
            }
        }
    }

    free(key);
    free(mstSet);

    return totalCost;
}
