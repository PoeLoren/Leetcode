class Solution {
public:
    int trap(int A[], int n) {
        int maxHeight = 0;
        vector<int> maxLeft(n);
        for(int i = 0;i < n;i++)
        {
            maxLeft[i] = maxHeight;
            maxHeight = max(maxHeight, A[i]);
        }
        maxHeight = 0;
        vector<int> maxRight(n);
        for(int i = n -1;i >= 0; i--)
        {
            maxRight[i] = maxHeight;
            maxHeight = max(maxHeight, A[i]);
        }
        
        int water = 0;
        for(int i = 0;i < n;i++)
        {
            int t = min(maxLeft[i],maxRight[i]) - A[i];
            if(t > 0)
                water += t;
        }
        return water;
    }
};