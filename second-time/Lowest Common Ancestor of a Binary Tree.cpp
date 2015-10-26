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
    vector<TreeNode*> path;
    bool isFound = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        if(root == p || root == q)
            return root;
        TreeNode* L = lowestCommonAncestor(root->left, p, q);
        TreeNode* R = lowestCommonAncestor(root->right, p, q);
        if(L && R)
            return root;
        return L ? L : R;
    }
};

class Solution {
public:
    vector<TreeNode*> path;
    bool isFound = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL)
            return NULL;
        findPath(root, p);
        vector<TreeNode*> pathp = path;
        path.clear();
        isFound = false;
        findPath(root, q);
        int i = 0;
        for(; i < path.size() && i < pathp.size(); ++i)
        {
            if(path[i] != pathp[i])
                break;
        }
        return path[i - 1];
    }
    
    void findPath(TreeNode* root, TreeNode* target)
    {
        if(root == NULL || isFound)
            return;
        path.push_back(root);
        if(root == target)
        {
            isFound = true;
            return;
        }
        findPath(root->left, target);
        findPath(root->right, target);
        if(!isFound)
            path.pop_back();
        return;
    }
};