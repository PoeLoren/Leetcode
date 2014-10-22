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
    int maxDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        queue<TreeNode*> s;
        TreeNode* endNode = root;
        s.push(root);
        int level = 0;
        while(!s.empty()){
            TreeNode* cur = s.front();
            s.pop();
            if(cur->left)
                s.push(cur->left);
            if(cur->right)
                s.push(cur->right);
            if(cur == endNode){
                level++;
                if(!s.empty())
                    endNode = s.back();
            }
        }
        return level;
    }
};