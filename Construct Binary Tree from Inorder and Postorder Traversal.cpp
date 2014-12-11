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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        TreeNode* root = buildTree(inorder, postorder, 0, n, 0, n);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int s1, int e1, int s2, int e2)
    {
        if(s1 >= e1)
            return NULL;
        int rootVal = postorder[e2-1];
        TreeNode* root = new TreeNode(rootVal);
        int k;
        for(k = s1;k < e1;k++)
        {
            if(inorder[k] == rootVal)
                break;
        }
        int leftTreeLen = k - s1;
        int rightTreeLen = e2 - 1 - k;
        root->left = buildTree(inorder, postorder, s1, k, s2, s2 + leftTreeLen);
        root->right = buildTree(inorder, postorder, k + 1, e1, s2 + leftTreeLen, e2 - 1);
        return root;
    }
};