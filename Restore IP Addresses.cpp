class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12)
            return res;
        string str;
        check(str,0,s);
        return res;
    }
    void check(string str,int dot,string rest){
        if(dot == 3){
            if(isValid(rest)){
                str += rest;
                res.push_back(str);
            }
        }else{
            for(int i = 0;i < 3 && i<rest.size();i++){
                string tmpstr = rest.substr(0,i+1);
                string tmprest = rest.substr(i+1,rest.size()-i-1);
                if(isValid(tmpstr)){
                    tmpstr = str + rest.substr(0,i+1);
                    tmpstr += '.';
                    check(tmpstr,dot+1,tmprest);
                }
            }
        }
    }
    
    bool isValid(string s){
        if(s[0] == '0' && s.size() != 1 || s.empty())
            return false;
        int num = atoi(s.c_str());
        return num >=0 && num <= 255;
    }
};