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