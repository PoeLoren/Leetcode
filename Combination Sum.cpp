class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        dfs(res,path,target,candidates,0,0);
        return res;
    }
    
    void dfs(vector<vector<int> > &res,vector<int> &path,int target,vector<int> &c,int sum,int cur){
        if(sum > target || cur >= c.size()){
            return ;
        }
        if(sum == target ){
            res.push_back(path);
            return ;
        }else if(sum < target){
            for(int i = cur;i < c.size();i++){
                path.push_back(c[i]);
                dfs(res,path,target,c,sum+c[i],i);
                path.pop_back();
            }
        }
    }
};