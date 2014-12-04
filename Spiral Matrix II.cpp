class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int> (n,0));
        fill(res,1,n - 1,0);
        return res;
    }
    
    void fill(vector<vector<int> > &res,int k,int n,int s)
    {
        if(n < 0)
            return ;
        if(n == 0)
        {
            res[s][s] = k;
            return ;
        }
        int i = s;
        for(;i < s + n;i++,k++)
        {
            res[s][i] = k;
        }
        int j = s;
        for(;j < s + n;j++,k++)
        {
            res[j][i] = k;
        }
        for(;i > s;i--,k++)
        {
            res[j][i] = k;
        }
        for(;j > s;j--,k++)
        {
            res[j][s] = k;
        }
        fill(res,k,n-2,s + 1);
    }
};