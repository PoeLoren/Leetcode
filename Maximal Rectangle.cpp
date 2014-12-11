class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int f[n][m + 1];
        for(int i = 0; i < m;i++)
        {
            if(matrix[0][i] == '1')
                f[0][i] = 1;
            else
                f[0][i] = 0;
        }
        for(int i = 1;i < n;i++)
        {
            for(int j = 0; j < m;j++)
            {
                if(matrix[i][j] == '0')
                    f[i][j] = 0;
                else
                    f[i][j] = f[i-1][j] + 1;
            }
        }
        int res = 0;
        for(int i = 0;i < n;i++)
        {
            int maxArea = maxRec(f[i],m);
            res = max(res, maxArea);
        }
        return res;
    }
    
    int maxRec(int a[], int m)
    {
        stack<int> s;
        int i = 0;
        int res = 0;
        a[m] = 0;
        while(i <= m)
        {
            if(s.empty() || a[i] >= a[s.top()])
            {
                s.push(i);
                i++;
            }
            else
            {
                int cur = s.top();
                s.pop();
                res = max(res, a[cur] * (s.empty() ? i : (i - s.top() - 1)));
            
            }
        }
        return res;
    }

};