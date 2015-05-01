/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return false;
        bool res = false;
        res = dfs(root, root->val, sum);
        return res;
    }
    
    bool dfs(TreeNode* root, int cur, int sum)
    {
        if(root->left == NULL && root->right == NULL && cur == sum)
            return true;
        if(root->left && dfs(root->left, cur + root->left->val, sum))
            return true;
        if(root->right && dfs(root->right, cur + root->right->val, sum))
            return true;
        return false;
    }
};