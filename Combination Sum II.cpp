class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> path;
        sort(num.begin(),num.end());
        dfs(res,path,target,0,0,num);
        return res;
    }
    
    void dfs(vector<vector<int> > &res,vector<int> &path,int target,int sum, int cur,vector<int> &num){
        if(sum > target || cur > num.size())
            return ;
        if(sum == target){
            res.push_back(path);
        }else{
            int previous = -1;
            for(int i = cur;i < num.size();i++){
                if(i != cur && num[i] == num[i-1])
                    continue;
                if(sum + num[i] > target)
                    return ;
                path.push_back(num[i]);
                dfs(res,path,target,sum+num[i],i+1,num);
                path.pop_back();
            }
        }
    }
};