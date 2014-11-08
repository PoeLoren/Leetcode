class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generate(1,n);
    }
    
    vector<TreeNode* > generate(int start,int end){
        vector<TreeNode*> res;
        if(start > end){
            res.push_back(NULL);
            return res;
        }
        for(int i = start; i <= end;i++){
            auto left = generate(start,i-1);
            auto right = generate(i+1,end);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};