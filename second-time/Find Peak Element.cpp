class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return 0;
        int res = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i - 1])
                res = i;
        }
        return res;
    }
};