class Solution {
public:
    int jump(vector<int>& nums) {
        int curMax = 0;
        int lastMax = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(lastMax < i)
            {
                res++;
                lastMax = curMax;
            }
            curMax = max(curMax, nums[i] + i);
        }
        return res;
    }
};