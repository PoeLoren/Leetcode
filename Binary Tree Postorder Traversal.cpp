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

class Solution {
public:
   vector<int> postorderTraversal(TreeNode *root)   
    {  
        vector<int> rs;  
        if (!root) return rs;  //若为空树，则返回空vector
        stack<TreeNode *> stk;  
        stk.push(root);  //当前节点入栈
        while (!stk.empty())  
        {  
            TreeNode *t = stk.top();  //栈顶节点出栈、输出
            stk.pop();  
            rs.push_back(t->val);  
            //注意，下面入栈顺序不能错 ，因为先左后右，
            //这样出栈时先遍历才是右（中->右->左）
            if (t->left) stk.push(t->left);  
            if (t->right) stk.push(t->right);  
        }  
        reverse(rs.begin(), rs.end());  //逆序，就成了后序遍历了
        return rs;  
    }  
};