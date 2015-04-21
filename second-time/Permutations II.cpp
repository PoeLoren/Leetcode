class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        permute(res, 0, num);
        return res;
    }
    
    bool canSwap(int k, int end, vector<int>& num)
    {
        for(int i = k; i < end; ++i)
        {
            if(num[i] == num[end])
                return false;
        }
        return true;
    }
    
    void permute(vector<vector<int> >& res, int k, vector<int>& num)
    {
        if(k == num.size())
            res.push_back(num);
        for(int i = k;i < num.size(); ++i)
        {
            if(canSwap(k, i, num))
            {
                swap(num[i], num[k]);
                permute(res, k + 1, num);
                swap(num[i], num[k]);
            }
        }
    }
};