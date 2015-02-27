class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        fill_n(&dp[0][0], n * n, false);
        for(int i = 0; i < n; ++i){
            dp[i][i] = true;
        }
        int maxlen = 1;
        int maxj = 0;
        for(int i = 1; i < n; ++i)
            for(int j = 0; j + i < n; ++j){
                if(((i < 2 )|| (dp[j + 1][j + i - 1])) && s[j] == s[j + i]){
                    dp[j][j + i] = true;
                    if(maxlen < i + 1){
                        maxlen = i + 1;
                        maxj = j;
                    }
                }
            }
        return s.substr(maxj, maxlen);
    }
};