class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> path;
        sort(S.begin(), S.end());
        dfs(0, S, res, path);
        return res;
    }
    
    void dfs(int k, vector<int>& s, vector<vector<int> >& res, vector<int>& path)
    {
        res.push_back(path);
        for(int i = k; i < s.size(); ++i)
        {
            if(i != k && s[i] == s[i - 1])
                continue;
            path.push_back(s[i]);
            dfs(i + 1, s, res, path);
            path.pop_back();
        }
    }
};