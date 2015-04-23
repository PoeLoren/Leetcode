class Solution {
public:
    int totalNQueens(int n) {
        vector<int> path(n);
        int res;
        solve(res, path, 0, n);
        return res;
    }
    
    void solve(int& res, vector<int>& path, int cur, int n)
    {
        if(cur == n)
        {
            res++;
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

    
