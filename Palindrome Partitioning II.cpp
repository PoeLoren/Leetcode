class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        bool p[n][n];
        fill_n(&p[0][0],n*n,false);
        int f[n+1];
        for(int i = 0; i <= n;i++)
            f[i] = n-1-i;
        for(int i = n-1;i>=0;i--){
            for(int j = i;j < n;j++){
                if(s[i] == s[j] && ((j-i < 2) || p[i+1][j-1])){
                    p[i][j] = true;
                    f[i] = min(f[i],f[j+1]+1);
                }
            }
        }
        return f[0];
    }
};