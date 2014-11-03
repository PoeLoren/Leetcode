class Solution {
public:
    vector<TreeNode*> vec;
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        pre_order(root);
        for(int i = 0;i < vec.size()-1;i++){
            vec[i]->left = NULL;
            vec[i]->right = vec[i+1];
        }
        vec[vec.size()-1]->left = NULL;
        vec[vec.size()-1]->right = NULL;
    }
    
    void pre_order(TreeNode* root){
        if(root == NULL)
            return;
        vec.push_back(root);
        pre_order(root->left);
        pre_order(root->right);
        return;
    }
};


lass Solution {
public:
void flatten(TreeNode *root) {
	if (root == nullptr) return; // 终止条件
	flatten(root->left);
	flatten(root->right);
	if (nullptr == root->left) return;
	// 三方合并，将左子树所形成的链表插入到root 和root->right 之间
	TreeNode *p = root->left;
	while(p->right) p = p->right; //寻找左链表最后一个节点
	p->right = root->right;
	root->right = root->left;
	root->left = nullptr;
}
};