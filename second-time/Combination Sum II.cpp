class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        cntCombination(0, candidates, 0, target, tmp, res);
        return res;
    }
    
    void cntCombination(int i, vector<int>& candidates, int sum, int target, vector<int>& tmp, vector<vector<int> >& res)
    {
        if(sum > target || i > candidates.size())
            return;
        if(sum == target)
        {
            res.push_back(tmp);
            return;
        }
        
        for(int j = i; j < candidates.size(); ++j)
        {
            if(j != i && candidates[j] == candidates[j - 1])//保证每一次选择不同
                continue;
            if(sum + candidates[i] > target)
                return;
            tmp.push_back(candidates[j]);
            cntCombination(j + 1, candidates, sum + candidates[j], target, tmp, res);//j + 1,保证每一个数只会选一次
            tmp.pop_back();
        }
        return;
    }
};