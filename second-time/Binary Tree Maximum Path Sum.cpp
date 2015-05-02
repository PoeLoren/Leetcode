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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        greedy(root, res);
        return res;
    }
    
    int greedy(TreeNode* root, int& res)
    {
        if(root == NULL)
            return 0;
        int left = greedy(root->left, res);
        int right = greedy(root->right, res);
        int cur = max(root->val, max(root->val + left, root->val + right));
        res = max(res, max(cur, root->val + left + right));
        return cur;
    }
};