class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]] = false;
        }
        int maxLen = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(m[nums[i]])
                continue;
            int len = 1;
            for(int j = nums[i] + 1; m.find(j) != m.end(); ++j)
            {
                len++;
                m[j] = true;
            }
            for(int j = nums[i] - 1; m.find(j) != m.end(); --j)
            {
                len++;
                m[j] = true;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};