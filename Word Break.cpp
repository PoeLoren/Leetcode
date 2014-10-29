class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> p(n+1,false);//p[i] means s[0,i] is in dict, p[i] = any of p[j] && s[j+1,i] in dict
        p[0] = true;//null string
        for(int i = 1;i<= n;i++){
            for(int j = 0;j < i;j++){
                if(p[j] && dict.find(s.substr(j,i-j)) != dict.end()){
                    p[i] = true;
                    break;
                }
            }
        }
        return p[n];
    }
};