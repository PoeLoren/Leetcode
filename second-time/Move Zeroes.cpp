class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while(i < nums.size() && nums[i] != 0)
            ++i;
        int cur = i;
        for(; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
            {
                swap(nums[cur], nums[i]);
                cur++;
            }
        }
    }
};