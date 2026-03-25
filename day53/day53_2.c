/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []*/
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if(root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** ans = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));

    struct TreeNode* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;

    while(front < rear) {
        int size = rear - front;
        ans[*returnSize] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = size;

        for(int i = 0; i < size; i++) {
            struct TreeNode* node = q[front++];
            ans[*returnSize][i] = node->val;

            if(node->left) q[rear++] = node->left;
            if(node->right) q[rear++] = node->right;
        }

        (*returnSize)++;
    }

    return ans;
}