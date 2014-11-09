class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if(numRows == 0)
            return res;
        res.resize(numRows);
        res[0].push_back(1);
        for(int i = 1;i < numRows;i++){
            for(int j = 0;j < res[i-1].size();j++){
                if(j == 0)
                    res[i].push_back(1);
                else{
                    
                    res[i].push_back(res[i-1][j-1] + res[i-1][j]);
                }
                
            }
            res[i].push_back(1);
        }
        return res;
    }
};