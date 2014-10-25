/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<TreeLinkNode*> q;
        TreeLinkNode* endNode = root;
        q.push(root);
        while(!q.empty()){
            TreeLinkNode* cur = q.front();
            q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            if(cur == endNode){
                cur->next = NULL;
                if(!q.empty())
                    endNode = q.back();
            }else{
                cur->next = q.front();
            }
            
        }
    }
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root || !root->left)  return;
        
        auto parent = root, son = root->left;
        
        while (son)
        {
            auto back = son;
            
            while (son)
            {
                son->next = parent->right;
                son = son->next;
                parent = parent->next;
                son->next = parent?parent->left:nullptr;
                son = son->next;
            }
            
            parent = back;
            son = parent->left;
        }
    }
};