/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp, *newNode;
    int value, i;

    if (n <= 0)
        return NULL;

    // Create first node
    scanf("%d", &value);
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = head;   // circular link
    temp = head;

    // Create remaining nodes
    for (i = 1; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        newNode->next = head; // point to head
        temp->next = newNode; // previous node link
        temp = newNode;
    }

    return head;
}

// Function to traverse circular linked list
void traverseList(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);   // stop when back to head
}

int main() {
    int n;
    struct Node* head;

    scanf("%d", &n);

    head = createList(n);
    traverseList(head);

    return 0;
}