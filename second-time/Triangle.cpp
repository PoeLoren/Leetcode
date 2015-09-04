class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        int m = triangle.size();
        vector<vector<int> > minimum(m, vector<int> (m, 0));
        for(int i = 0; i < m; ++i)
        {
            minimum[m - 1][i] = triangle[m - 1][i];
        }
        for(int i = m - 2; i >= 0; --i)
        {
            for(int j = 0; j <= i; ++j)
            {
                minimum[i][j] = triangle[i][j] + min(minimum[i+1][j], minimum[i + 1][j + 1]);
            }
        }
        return minimum[0][0];
    }
};