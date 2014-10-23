class Solution {
public:
    vector<vector<int> > res;
    vector<bool> flag;
    vector<vector<int> > permute(vector<int> &num) {
        vector<int> cur;
        flag.resize(num.size());
        fill(flag.begin(),flag.end(),false);
        dfs(num,cur,0,num.size());
        return res;
    }
    
    void dfs(vector<int>& num, vector<int>& cur,int n,int target){
        if(n == target){
            res.push_back(cur);
        }
        for(int i = 0; i < num.size();i++){
            if(!flag[i]){
                flag[i] = true;
                cur.push_back(num[i]);
                dfs(num,cur,n+1,target);
                flag[i] = false;
                cur.pop_back();
            }
        }
    }
};