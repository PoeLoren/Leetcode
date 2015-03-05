class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string m[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        if(digits.empty())
            return res;
        res.push_back("");
        for(int i = 0; i < digits.size(); ++i){
            int num = digits[i] - '0';
            vector<string> tmpRes;
            for(int j = 0; j < res.size(); ++j){
                for(int k = 0; k < m[num].size(); ++k){
                    string tmp = res[j] + m[num][k];
                    tmpRes.push_back(tmp);
                }
            }
            res = tmpRes;
        }
        return res;
    }
};