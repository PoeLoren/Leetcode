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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* endNode = root;
        vector<int> level;
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            level.push_back(cur->val);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            if(cur == endNode)
            {
                res.push_back(level);
                level.clear();
                if(!q.empty())
                    endNode = q.back();
            }
        }
        return res;
    }
};