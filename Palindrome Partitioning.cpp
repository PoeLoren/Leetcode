class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int n = s.size();
        vector<vector<string> > res[n];
        bool p[n][n];
        fill_n(&p[0][0],n * n,false);
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n;j++){
                if(s[i] == s[j]){
                    p[i][j] = (j - i < 2) || p[i+1][j-1];
                }
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n;j++){
                if(p[i][j]){
                    string pali = s.substr(i,j-i+1);
                    if(j + 1 < n){
                        for(auto v:res[j+1]){
                            v.insert(v.begin(),pali);
                            res[i].push_back(v);
                        }
                    }else{
                        res[i].push_back(vector<string> {pali});
                    }
                }
            }
        }
        return res[0];
        
    }
};