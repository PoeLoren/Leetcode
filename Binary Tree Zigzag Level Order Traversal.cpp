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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode* > q;
        TreeNode* endNode = root;
        vector<vector<int> > res;
        if(root == NULL)
            return res;
        vector<int> vec;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            TreeNode* cur = q.front();
            vec.push_back(cur->val);
            q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            
            if(cur == endNode){
                if(level & 0x1)
                    reverse(vec.begin(),vec.end());
                res.push_back(vec);
                level++;
                vec.clear();
                if(!q.empty())
                    endNode = q.back();
            }
        }
        return res;
    }
};