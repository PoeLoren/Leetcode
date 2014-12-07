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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty())
            return NULL;
        int n = preorder.size();
        TreeNode* root  = buildTree(preorder, inorder, 0, n, 0, n);
        return root;
    }
    
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder, int s1, int e1, int s2, int e2)
    {
        if(s1 >= e1)
            return NULL;
        int rootVal = preorder[s1];
        TreeNode* root = new TreeNode(rootVal);
        int i = s2;
        for(; i < e2; i++)
        {
            if(inorder[i] == rootVal)
                break;
        }
        int leftTreeLen = i - s2;
        int rightTreeLen = e2 - i - 1;
        root->left = buildTree(preorder, inorder, s1 + 1, s1 + 1 + leftTreeLen, s2, s2 + leftTreeLen);
        root->right = buildTree(preorder, inorder, s1 + leftTreeLen + 1, s1 + 1 + leftTreeLen + rightTreeLen, i + 1, i + 1 + rightTreeLen);
        return root;
    }
};