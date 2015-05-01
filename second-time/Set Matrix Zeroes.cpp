class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> row;
        unordered_set<int> col;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
        auto it = row.begin();
        for(; it != row.end(); ++it)
        {
            for(int j = 0; j < n; ++j)
                matrix[*it][j] = 0;
        }
        it = col.begin();
        for(; it != col.end(); ++it)
        {
            for(int j = 0; j < m; ++j)
                matrix[j][*it] = 0;
        }
        return ;
    }
};