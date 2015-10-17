class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num = 0;
        for(int i = 0; i < nums.size(); ++i)
            num ^= nums[i];
        int m = 1;
        for(int i = 0; i < 32; ++i)
        {
            m = 1 << i;
            if(num & m)
                break;
        }
        vector<int> nums1;
        vector<int> nums2;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] & m)
                nums1.push_back(nums[i]);
            else
                nums2.push_back(nums[i]);
        }
        int n = 0;
        for(int i = 0; i < nums1.size(); ++i)
        {
            n ^= nums1[i];
        }
        res.push_back(n);
        n = 0;
        for(int i = 0; i < nums2.size(); ++i)
        {
            n ^= nums2[i];
        }
        res.push_back(n);
        return res;
    }
};