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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* endNode = root;
        vector<vector<int> > ret;
        if(root == NULL)
            return ret;
        vector<int> level;
        while(!q.empty()){
            TreeNode* cur = q.front();
			level.push_back(cur->val);
            q.pop();
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
            if(cur == endNode){
                ret.insert(ret.begin(),level);
                level.clear();
				if(!q.empty())
                    endNode = q.back();
            }
            
        }
        return ret;
    }
};