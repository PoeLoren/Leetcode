class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int> > res;
        vector<int> path;
        dfs(res,path,0,S);
        return res;
    }
    
    void dfs(vector<vector<int> > &res,vector<int> &path,int start,vector<int> &S){
        res.push_back(path);
        for(int i = start; i < S.size(); i++){
            if(i != start && S[i] == S[i-1])
                continue;
            path.push_back(S[i]);
            dfs(res,path,i+1,S);
            path.pop_back();
        }
    }
};