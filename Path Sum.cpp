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
    bool res;
    bool hasPathSum(TreeNode *root, int sum) {
        int num = 0;
        res = false;
        if(root == NULL)
            return false;
        dfs(root,root->val,sum);
        return res;
    }
    
    void dfs(TreeNode* root,int num,int sum){
        if(root->left == NULL && root->right == NULL){
            if(num == sum)
                res = true;
        }else{
            if(root->left)
                dfs(root->left,root->left->val+num,sum);
            if(root->right)
                dfs(root->right,root->right->val+num,sum);
        }
    }
};