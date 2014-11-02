class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(NULL == root)
            return 0;
        int res = 0;
        dfs(root,root->val,res);
        return res;
    }
    
    void dfs(TreeNode* root ,int sum,int& res){
        if(root->left == NULL && root->right == NULL){
            res += sum;
            return;
        }
        if(root->left)
            dfs(root->left,sum*10 + root->left->val,res);
        if(root->right)
            dfs(root->right,sum*10 + root->right->val,res);
        
    }
};