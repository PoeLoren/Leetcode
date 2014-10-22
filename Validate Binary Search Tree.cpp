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
    bool isValidBST(TreeNode *root) {
        return isValid(root,INT_MIN,INT_MAX);
    }
    
    bool isValid(TreeNode* root,int low,int high){
        if(root == NULL)
            return true;
        if(root->val < high && root->val > low){
            return isValid(root->left,low,root->val) && isValid(root->right,root->val,high);
        }else{
            return false;
        }
    }
};