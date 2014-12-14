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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root == NULL)
            return res;
        TreeNode* pre = NULL;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* cur = s.top();
            if(cur->left == NULL && cur->right == NULL ||(pre != NULL && (pre == cur->left || pre == cur->right)))
            {
                res.push_back(cur->val);
                s.pop();
                pre = cur;
            }
            else
            {
                if(cur->right)
                    s.push(cur->right);
                if(cur->left)
                    s.push(cur->left);
            }
        }
        return res;
        
    }
};