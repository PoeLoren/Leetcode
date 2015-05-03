class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int> > res;
        dfs(path, res, n, k, 0, 0);
        return res;
    }
    
    void dfs(vector<int>& path, vector<vector<int> >& res, int n, int k, int cur, int j)
    {
        if(cur == k)
        {
            res.push_back(path);
            return;
        }
        for(int i = j; i < n; ++i)
        {
            path.push_back(i + 1);
            dfs(path, res, n, k, cur + 1, i + 1);
            path.pop_back();
        }
        return;
    }
};