/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
*/
struct TreeNode* build(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if(inStart > inEnd)
        return NULL;

    int val = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = NULL;
    root->right = NULL;

    if(inStart == inEnd)
        return root;

    int index;
    for(index = inStart; index <= inEnd; index++) {
        if(inorder[index] == val)
            break;
    }

    root->right = build(inorder, postorder, index + 1, inEnd, postIndex);
    root->left = build(inorder, postorder, inStart, index - 1, postIndex);

    return root;
}