/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

/* Structure of Node */
struct Node
{
    int data;
    struct Node *next;
};

/* Function to create a new node */
struct Node* createNode(int data)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert node at end */
struct Node* insert(struct Node* head, int data)
{
    struct Node* newNode = createNode(data);

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Find length of list */
int getLength(struct Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

/* Find intersection */
void findIntersection(struct Node* head1,
                      struct Node* head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    /* Move pointer of longer list */
    if(len1 > len2)
        while(diff--) head1 = head1->next;
    else
        while(diff--) head2 = head2->next;

    /* Traverse both lists */
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data == head2->data)
        {
            printf("%d", head1->data);
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    printf("No Intersection");
}

/* Main Function */
int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    int n, m, x, i;

    /* First List */
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head1 = insert(head1, x);
    }

    /* Second List */
    scanf("%d", &m);
    for(i = 0; i < m; i++)
    {
        scanf("%d", &x);
        head2 = insert(head2, x);
    }

    findIntersection(head1, head2);

    return 0;
}