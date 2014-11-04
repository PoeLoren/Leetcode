class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        vector<int> res;
        if(root == NULL)
            return res;
        TreeNode* cur = root;
        while(!s.empty()||cur != NULL){
            if(cur){
                res.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }else{
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};