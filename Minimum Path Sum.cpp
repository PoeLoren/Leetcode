class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int p[m][n];
        p[0][0] = grid[0][0];
        for(int i = 1; i< m;i++){
            p[i][0] = p[i-1][0] + grid[i][0];
        }
        for(int i = 1; i< n;i++){
            p[0][i] = p[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < m; i++)
            for(int j = 1;j < n;j++){
                p[i][j] = min(p[i][j-1], p[i-1][j]) + grid[i][j];
            }
        return p[m-1][n-1];
    }
};