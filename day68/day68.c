/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

*/
#include <stdlib.h>

// Queue implementation
typedef struct {
    int* data;
    int front, rear;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(size * sizeof(int));
    q->front = q->rear = 0;
    return q;
}

void enqueue(Queue* q, int x) {
    q->data[q->rear++] = x;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Topological Sort
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {

    // Adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }

    int* indegree = (int*)calloc(numCourses, sizeof(int));

    // Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];

        adj[u][adjSize[u]++] = v;
        indegree[v]++;
    }

    // Queue
    Queue* q = createQueue(numCourses);

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            enqueue(q, i);
    }

    int* result = (int*)malloc(numCourses * sizeof(int));
    int index = 0;

    // BFS
    while (!isEmpty(q)) {
        int node = dequeue(q);
        result[index++] = node;

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
                enqueue(q, neighbor);
        }
    }

    // Check if valid topo sort
    if (index != numCourses) {
        *returnSize = 0;
        return result; // empty (cycle exists)
    }

    *returnSize = numCourses;
    return result;
}