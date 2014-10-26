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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> vec;
        dfs(root,0,sum,vec,res);
        return res;
    }
    
    void dfs(TreeNode *root,int cur,int sum ,vector<int> &vec,vector<vector<int> > &res){
        if(root == NULL)
            return ;
        vec.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == cur + root->val){
                res.push_back(vec);
            }
        }
        dfs(root->left,cur+root->val,sum,vec,res);
        dfs(root->right,cur+root->val,sum,vec,res);
        vec.pop_back();
        
    }
};