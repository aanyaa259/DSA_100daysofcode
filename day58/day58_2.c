/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]*/
struct TreeNode* build(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if(inStart > inEnd)
        return NULL;

    int val = preorder[*preIndex];
    (*preIndex)++;

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

    root->left = build(preorder, inorder, inStart, index - 1, preIndex);
    root->right = build(preorder, inorder, index + 1, inEnd, preIndex);

    return root;
}