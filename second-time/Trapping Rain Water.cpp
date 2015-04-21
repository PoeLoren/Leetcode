class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size());
        int left = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            maxLeft[i] = left;
            left = max(left, height[i]);
        }
        vector<int> maxRight(height.size());
        int right = 0;
        for(int i = height.size() - 1; i >= 0; --i)
        {
            maxRight[i] = right;
            right = max(right, height[i]);
        }
        int res = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            int t = min(maxLeft[i] , maxRight[i]) - height[i];
            if(t > 0)
                res += t;
        }
        return res;
    }
};