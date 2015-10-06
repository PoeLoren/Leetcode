class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(k, 0, n, 0, 0, path);
        return res;
    }
    
    void dfs(int k, int num, int n, int cur, int curNum, vector<int>& path)
    {
        if(num > k || cur > n)
            return ;
        if(num == k && cur == n)
        {
            res.push_back(path);
            return;
        }
        for(int i = curNum + 1; i <= 9; ++i)
        {
            path.push_back(i);
            dfs(k, num + 1, n, cur + i, i, path);
            path.pop_back();
        }
        
    }
};