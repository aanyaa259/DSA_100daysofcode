/*A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

// Queue structure
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void enqueue(Queue* q, int x) {
    q->data[q->rear++] = x;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Main function
char* findOrder(char dict[][100], int N, int K) {
    
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int present[MAX] = {0};

    // Mark present characters
    for (int i = 0; i < N; i++) {
        for (int j = 0; dict[i][j]; j++) {
            present[dict[i][j] - 'a'] = 1;
        }
    }

    // Build graph
    for (int i = 0; i < N - 1; i++) {
        char* w1 = dict[i];
        char* w2 = dict[i + 1];

        int len1 = strlen(w1);
        int len2 = strlen(w2);
        int found = 0;

        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        // Invalid case
        if (!found && len1 > len2)
            return "";
    }

    // Queue
    Queue q;
    q.front = q.rear = 0;

    for (int i = 0; i < K; i++) {
        if (present[i] && indegree[i] == 0)
            enqueue(&q, i);
    }

    char* result = (char*)malloc((K + 1) * sizeof(char));
    int index = 0;

    // Topological sort
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        result[index++] = u + 'a';

        for (int v = 0; v < K; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    enqueue(&q, v);
            }
        }
    }

    result[index] = '\0';

    // Check cycle
    int count = 0;
    for (int i = 0; i < K; i++)
        if (present[i]) count++;

    if (index != count)
        return "";

    return result;
}

// Example driver
int main() {
    char dict[5][100] = {"baa", "abcd", "abca", "cab", "cad"};
    int N = 5, K = 4;

    char* order = findOrder(dict, N, K);

    if (strlen(order) == 0)
        printf("Invalid order\n");
    else
        printf("Order: %s\n", order);

    return 0;
}