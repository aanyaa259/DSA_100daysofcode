/*Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.


*/
#include <stdbool.h>
#include <stdlib.h>

/* Definition for singly-linked list */
struct ListNode {
    int val;
    struct ListNode *next;
};

bool removeCycle(struct ListNode *head)
{
    if(head == NULL || head->next == NULL)
        return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    /* Step 1: Detect Cycle */
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    /* No Cycle */
    if(fast == NULL || fast->next == NULL)
        return false;

    /* Step 2: Find starting node of cycle */
    slow = head;

    if(slow == fast)
    {
        while(fast->next != slow)
            fast = fast->next;
    }
    else
    {
        while(slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* Step 3: Remove cycle */
    fast->next = NULL;

    return true;
}