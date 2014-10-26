class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int> > res;
        if(S.empty())
            return res;
        vector<int> path;
        dfs(S,0,path,res);
        return res;
    }
    
    void dfs(vector<int> &s,int step,vector<int> &path,vector<vector<int> > &res){
        if(step == s.size()){
            res.push_back(path);
            return;
        }else{
            dfs(s,step+1,path,res);
            path.push_back(s[step]);
            dfs(s,step+1,path,res);
            path.pop_back();
        }
    }