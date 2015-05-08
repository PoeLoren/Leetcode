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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if(root)
            dfs(root, res, root->val);
        return res;
    }
    
    void dfs(TreeNode* root, int &res, int cur)
    {
        if(root->left == NULL && root->right == NULL)
        {
            res += cur;
            return;
        }
        if(root->left)
            dfs(root->left, res, cur * 10 + root->left->val);
        if(root->right)
            dfs(root->right, res, cur * 10 + root->right->val);
    }
};