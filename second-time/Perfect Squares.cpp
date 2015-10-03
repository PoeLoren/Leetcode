class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n) + 1;
        vector<int> a(m);
        for(int i = 0; i * i <= n; ++i)
        {
            a[i] = (i + 1) * (i + 1);
        }
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(i - a[j] >= 0 && dp[i-a[j]] + 1 < dp[i])
                    dp[i] = dp[i-a[j]] + 1;
            }
        }
        return dp[n];
    }
};