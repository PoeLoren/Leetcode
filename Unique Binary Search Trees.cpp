class Solution {
public:
    int numTrees(int n) {
        vector<int> res;
        res.resize(n+1);
        res[0] = 1;
        res[1] = 1;
        for(int i = 2;i <= n;i++){
            res[i] = 0;
            for(int j = 0;j < i;j++){
                res[i] += res[j] * res[i-j-1];//dp, the kind of left subtree muitiply the kind of right subtree
            }
        }
        return res[n];
    }
};