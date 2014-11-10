class Solution {
public:
    void recover(TreeNode* root){
        if(root == NULL)
            return ;
        recover(root->left);
        if(pre && pre->val > root->val){
            if(s1 == NULL){
                s1 = pre;
                s2 = root;
            }else{
                s2 = root;
            }
        }
        pre = root;
        recover(root->right);
    }
    void recoverTree(TreeNode *root) {
        if(root == NULL)
            return;
        pre = s1 = s2 = NULL;
        recover(root);
        swap(s1->val,s2->val);
        return;
    }
private:
    TreeNode* pre;
    TreeNode* s1,*s2;
};