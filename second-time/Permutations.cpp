class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        permute(res, 0, num);
        return res;
    }
    
    void permute(vector<vector<int> >& res, int k, vector<int>& num)
    {
        if(k == num.size())
            res.push_back(num);
        for(int i = k; i < num.size(); ++i)
        {
            swap(num[i],num[k]);
            permute(res, k + 1, num);
            swap(num[i],num[k]);
        }
    }
};