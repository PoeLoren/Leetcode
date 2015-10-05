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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long long low, long long high)
    {
        if(root == NULL)
            return true;
        if(root->val > low && root->val < high)
            return isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high);
        return false;
    }
};