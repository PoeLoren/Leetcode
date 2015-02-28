class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty())
            return "";
        string res = strs[0];
        for(int i = 1; i < strs.size(); ++i){
            string tmp;
            for(int j = 0; j < res.size() && j < strs[i].size(); ++j)
                if(res[j] == strs[i][j])
                    tmp += res[j];
                else
                    break;
            res = tmp;
        }
        return res;
    }
};