class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.empty())
            return 0;
        if(height.size() == 1)
            return height[0];
        int n = height.size();
        vector<int> left(n,0);  //the index of first lower height in left
        vector<int> right(n,0); //the index of first lower height in right
        left[0] = -1;           //the index of left[0] is -1
        right[n-1] = n;
        for(int i = 1; i < n;i++)
        {
            int j = i-1;
            while(j != -1 && height[i] <= height[j])
            {
                j = left[j];
            }
            left[i] = j;
        }
        
        for(int i = n-2;i >= 0;i--)
        {
            int j = i + 1;
            while(j != n && height[i] <= height[j])
                j = right[j];
            right[i] = j;
        }
        int res = -1;
        for(int i = 0;i < n;i++)
        {
            res = max(res,height[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};

//http://blog.csdn.net/doc_sgl/article/details/11805519   
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        height.push_back(0);
        int i = 0;
        int res = 0;
        while(i < height.size())
        {
            if(s.empty() || height[i] >= height[s.top()])
                s.push(i++);
            else
            {
                int cur = s.top();
                s.pop();
                res = max(res,height[cur] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        return res;
    }
};