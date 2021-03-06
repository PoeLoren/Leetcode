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
    int res = 0;
    int kthSmallest(TreeNode* root, int k) {
        kth(root, k);
        return res;
    }
    
    void kth(TreeNode* root, int& k)
    {
        if(root == NULL)
            return ;
        kth(root->left, k);
        k--;
        if(k == 0)
        {
            res = root->val;
            return;
        }
        kth(root->right, k);
    }
};