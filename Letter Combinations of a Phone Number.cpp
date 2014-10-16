class Solution {
public:
    vector<string> res;
    const string m[11] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"," "};
    vector<string> letterCombinations(string digits) {
        string s = "";
        f(s,digits,0);
        return res;
    }
    void f(string& s,string& digits,int pos){
        if(pos == digits.size()){
            res.push_back(s);
            return;
        }else{
            for(int i = 0;i < m[digits[pos]-'0'].size();i++){
                s.push_back(m[digits[pos]-'0'][i]);
                f(s,digits,pos+1);
                s.pop_back();
            }
        }
    }
};