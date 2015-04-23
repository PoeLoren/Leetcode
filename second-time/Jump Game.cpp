class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
        int i = -1;
        while(i < cur)
        {
            ++i;
            cur = max(cur,nums[i] + i);
            if(cur >= nums.size() - 1)
                return true;
        }
        return false;
    }
};