class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        unordered_set<int> row;
        unordered_set<int> col;
        for(int i = 0; i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto it = row.begin();it != row.end();it++){
            for(int j = 0;j < matrix[0].size();j++){
                matrix[*it][j] = 0;
            }
        }
        for(auto it = col.begin();it != col.end();it++){
            for(int j = 0;j < matrix.size();j++){
                matrix[j][*it] = 0;
            }
        }
    }