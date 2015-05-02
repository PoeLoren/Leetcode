class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int> (n));
        fill(res, 0, 0, n - 1, 1);
        return res;
    }
    
    void fill(vector<vector<int> >& res, int x, int y, int len, int cur)
    {
        if(len < 0)
            return;
        if(len == 0)
        {
            res[x][y] = cur;
            return ;
        }
        int j = y;    
        for(; j < y + len; ++j)
            res[x][j] = cur++;
        int i = x;    
        for(; i < x + len; ++i)
            res[i][j] = cur++;
        for(; j > y; --j)
            res[i][j] = cur++;
        for(; i > x; --i)
            res[i][j] = cur++;
        fill(res, x + 1, y + 1, len - 2, cur);
    }
};