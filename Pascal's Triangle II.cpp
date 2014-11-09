class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        for(int i = 1; i <= rowIndex;i++){
            vector<int> tmp;
            for(int j = 0;j < res.size();j++){
                if(j == 0){
                    tmp.push_back(1);
                }else{
                    tmp.push_back(res[j-1] + res[j]);
                }
                
            }
            tmp.push_back(1);
            res = tmp;
        }
        return res;
    }
};