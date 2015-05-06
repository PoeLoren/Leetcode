class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int res = 1;
        int cnt = 1;
        int cur = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == cur)
            {
                ++cnt;
                if(cnt <= 2)
                    nums[res++] = cur;
            }
            else
            {
                cnt = 1;
                cur = nums[i];
                nums[res++] = cur;
            }
        }
        return res;
    }
};