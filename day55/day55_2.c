/*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

*/
int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root == NULL) return NULL;

    int* ans = (int*)malloc(1000 * sizeof(int));
    struct TreeNode* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;

    while(front < rear) {
        int size = rear - front;

        for(int i = 0; i < size; i++) {
            struct TreeNode* node = q[front++];

            if(i == size - 1)
                ans[(*returnSize)++] = node->val;

            if(node->left) q[rear++] = node->left;
            if(node->right) q[rear++] = node->right;
        }
    }

    return ans;
}
