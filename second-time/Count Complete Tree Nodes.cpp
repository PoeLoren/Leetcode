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
    int countNodes(TreeNode* root) {
        if(NULL == root)
            return 0;
        int left = getLeftHeight(root->left);
        int right = getRightHeight(root->right);
        if(left == right)
            return pow(2, left + 1) - 1;
        else
            return countNodes(root->left) + countNodes(root->right) + 1;
    }
    
    int getLeftHeight(TreeNode* root)
    {
        int height= 0;
        while(root)
        {
            root = root->left;
            height++;
        }
        return height;
    }
    int getRightHeight(TreeNode* root)
    {
        int height = 0;
        while(root)
        {
            root = root->right;
            height++;
        }
        return height;
    }
};