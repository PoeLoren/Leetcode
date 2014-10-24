//http://www.cnblogs.com/ganganloveu/p/3836519.html
class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        vector<vector<int> > dp(m+1,vector<int> (n+1,0));
        for(int i = 0; i< m+1;i++){
            dp[i][0] = 1;
        }
        for(int i = 1;i < m + 1;i++){
            for(int j = 1;j < n+1;j++){
                if(S[i-1] == T[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};