/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create new node
struct Node* createNode(int data)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Rotate list right by k places
struct Node* rotateRight(struct Node* head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *temp = head;
    int n = 1;

    // Find length and last node
    while (temp->next != NULL)
    {
        temp = temp->next;
        n++;
    }

    // Make circular list
    temp->next = head;

    k = k % n;   // handle k > n
    int steps = n - k;

    // Move to (n-k)th node
    struct Node *newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // Set new head
    struct Node *newHead = newTail->next;

    // Break circular link
    newTail->next = NULL;

    return newHead;
}

// Display list
void display(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, x, k;

    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        struct Node* newNode = createNode(x);

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}