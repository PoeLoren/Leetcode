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
    bool isBalanced(TreeNode *root) {
        int res = isBalancedCore(root);
        if(res == -1)
            return false;
        else 
            return true;
    }
    
    int isBalancedCore(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = isBalancedCore(root->left);
        int right = isBalancedCore(root->right);
        if(left == -1 || right == -1)
            return -1;
        if(abs(left - right) <= 1)
            return 1 + max(left, right);
        else
            return -1;
    }
};