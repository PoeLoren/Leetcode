class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty() || prices.size() == 1)
            return 0;
        int premin = min(prices[0],prices[1]);
        int n = prices.size();
        int dp;
        dp = prices[1]-prices[0];
        dp = dp > 0 ? dp : 0;
        for(int i = 2;i < n;i++){
            if(prices[i] > premin){
                dp= max(dp,prices[i] -premin);
            }else{
                premin = prices[i];
            }
        }
        return dp;
    }