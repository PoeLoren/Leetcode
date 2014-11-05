class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int i = 0;
        int j = matrix[0].size()-1;
        while(i < matrix.size() && j >=0 && matrix[i][j] != target){
            if(matrix[i][j] < target)
                i++;
            else if(matrix[i][j] > target)
                j--;
            else
                break;
        }
        if(i == matrix.size() || j < 0)
            return false;
        else
            return true;
    }
};