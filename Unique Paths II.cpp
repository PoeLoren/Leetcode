class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int dp[101];
        int m = obstacleGrid.size()-1;
        int n = obstacleGrid[0].size()-1;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m][n] == 1)//if there is obstacle in start or end point
            return 0;
        memset(dp,0,sizeof(dp));
        dp[0] = 1;//if there is only one point
        for(int i = 0; i<= m;i++)
            for(int j = 0;j <= n;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                    continue;
                }
                if(j != 0)// if j == 0, dp[j] = previous dp[j],needn't count
                    dp[j] = dp[j] + dp[j-1];
            }
        return dp[n];
    }
};