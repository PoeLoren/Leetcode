class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while(target != matrix[i][j])
        {
            if(target > matrix[i][j])
            {
                if(i < m - 1)
                    i++;
                else
                    return false;
            }
            else
            {
                if(j > 0)
                    j--;
                else
                    return false;
            }
        }
        return true;
    }
};