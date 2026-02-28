/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Function to reverse linked list
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *nextNode = NULL;

    while (head != NULL) {
        nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {

    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Find middle
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode* secondHalf = reverse(slow->next);

    struct ListNode* firstHalf = head;
    struct ListNode* temp = secondHalf;

    // Compare both halves
    while (temp) {
        if (firstHalf->val != temp->val)
            return false;

        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return true;
}