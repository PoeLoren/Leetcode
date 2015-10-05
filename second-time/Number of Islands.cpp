class Solution {
public:
    int res;
    void dfs(int col, int row, vector<vector<char> >& grid, vector<vector<bool> >& visited)
    {
        if(col < 0 || row < 0 || col >= grid.size() || row >= grid[0].size())
            return;
        if(visited[col][row] || grid[col][row] == '0')
            return;
        visited[col][row] = true;
        dfs(col - 1, row, grid, visited);
        dfs(col + 1, row, grid, visited);
        dfs(col, row - 1, grid, visited);
        dfs(col, row + 1, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        res = 0;
        if(grid.empty())
            return res;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i = 0;  i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    res++;
                    dfs(i, j, grid, visited);
                }
            }
        
        return res;
    }
    
    
};