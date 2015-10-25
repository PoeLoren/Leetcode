class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = 1;
        vector<int> res(n, 1);
        for(int i = 0; i < nums.size(); ++i)
        {
            res[i] *= left;
            left *= nums[i];
            res[n - i - 1] *= right;
            right *= nums[n- i -1];
        }
        return res;
    }
};