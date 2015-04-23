class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> path(n);
        vector<vector<string> > res;
        solve(res, path, 0, n);
        return res;
    }
    
    void solve(vector<vector<string> >& res, vector<int>& path, int cur, int n)
    {
        if(cur == n)
        {
            vector<string> tmp;
            for(int i = 0; i < n; ++i)
            {
                string s;
                s.append(path[i],'.');
                s.push_back('Q');
                s.append(n - path[i] - 1,'.');
                tmp.push_back(s);
            }
            res.push_back(tmp);
            return;
        }
        for(int j = 0; j < n; ++j)
        {
            if(isValid(path, cur, j))
            {
                path[cur] = j;
                solve(res, path, cur + 1, n);
            }
        }
    }
    
    bool isValid(vector<int>& path, int row, int col)
    {
        for(int i = 0; i < row; ++i)
        {
            int j = path[i];
            if(i + col == j + row)
                return false;
            if(j == col)
                return false;
            if(i - col == row - j)
                return false;
        }
        return true;
    }
};