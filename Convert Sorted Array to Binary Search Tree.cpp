class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.empty())
            return NULL;
        TreeNode* root = convert(num,0,num.size());
        return root;
    }
    
    TreeNode* convert(vector<int> &num,int s,int e){
        if(s >= e)
            return NULL;
        int mid = (s + e) / 2;
        
        TreeNode* root = new TreeNode(num[mid]);
        TreeNode* left = convert(num,s,mid);
        TreeNode* right = convert(num,mid+1,e);
        root->left = left;
        root->right = right;
        return root;
    }
};