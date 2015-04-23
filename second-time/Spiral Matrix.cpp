class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        solve(0, 0, m, n, matrix, res);
        return res;
    }
    
    void solve(int row, int col, int m, int n, vector<vector<int> >& matrix, vector<int>& res)
    {
        if(n == 0 || m == 0)
            return ;
        if(n == 1)
        {
            for(int i = row; i < row + m; ++i)
                res.push_back(matrix[i][col]);
            return;
        }
        if(m == 1)
        {
            for(int i = col; i < col + n;++i)
                res.push_back(matrix[row][i]);
            return;
        }
        int i = row, j = col;
        for(; j < col + n - 1; ++j)
            res.push_back(matrix[i][j]);
        for(; i < row + m - 1; ++i)
            res.push_back(matrix[i][j]);
        for(; j > col; --j)
            res.push_back(matrix[i][j]);
        for(; i > row; --i)
            res.push_back(matrix[i][j]);
        solve(row + 1, col + 1, m - 2, n - 2,matrix, res);
        return;
    }
};