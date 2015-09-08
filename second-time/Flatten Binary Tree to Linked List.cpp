/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pre = new TreeNode(0);
    void flatten(TreeNode* root)
    {
        if(root == NULL)
            return;
        pre->right = root;
        pre = root;
        TreeNode* right = root->right;
        flatten(root->left);
        root->left = NULL;
        flatten(right);
    }
};