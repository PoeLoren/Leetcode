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
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        TreeNode* endNode = root;
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            if(cur->left == NULL && cur->right == NULL)
                return level;
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            if(cur == endNode){
                level++;
                if(!q.empty())
                    endNode = q.back();
            }
        }
        return level;
    }
};