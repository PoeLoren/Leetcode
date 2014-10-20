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
        return getHeight(root) >= 0;
    }
    int getHeight(TreeNode *root){
        if(root == NULL)
            return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if(l < 0 || r < 0 || abs(l-r) > 1)
            return -1;
        return max(l,r)+1;
    }
};