/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS to detect cycle
bool dfs(int node, int** adj, int* adjSize, bool* visited, bool* recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack)) {
                return true;
            }
        } 
        else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = false;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // Step 1: Build adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a; // edge b → a
    }

    // Step 2: visited + recursion stack
    bool* visited = (bool*)calloc(numCourses, sizeof(bool));
    bool* recStack = (bool*)calloc(numCourses, sizeof(bool));

    // Step 3: Check for cycle
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                return false; // cycle exists
            }
        }
    }

    return true; // no cycle
}