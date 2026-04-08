/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/
#include <stdio.h>
#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    
    // Step 1: Allocate graph
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    int* graphColSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int)); // worst case
    }

    // Step 2: Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        
        graph[b][graphColSize[b]++] = a;
        inDegree[a]++;
    }

    // Step 3: Queue
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 4: Result array
    int* result = (int*)malloc(numCourses * sizeof(int));
    int index = 0;

    // Step 5: BFS
    while (front < rear) {
        int curr = queue[front++];
        result[index++] = curr;

        for (int i = 0; i < graphColSize[curr]; i++) {
            int neighbor = graph[curr][i];
            inDegree[neighbor]--;

            if (inDegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    // Step 6: Check cycle
    if (index != numCourses) {
        *returnSize = 0;
        return (int*)malloc(0); // empty array
    }

    *returnSize = numCourses;
    return result;
}