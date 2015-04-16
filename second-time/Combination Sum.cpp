class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        cntCombination(0, candidates, 0, target, tmp, res);
        return res;
    }
    
    void cntCombination(int i, vector<int>& candidates, int sum, int target, vector<int>& tmp, vector<vector<int> >& res)
    {
        if(sum > target)
            return;
        if(sum == target)
        {
            res.push_back(tmp);
            return;
        }
        
        for(int j = i; j < candidates.size(); ++j)
        {
            tmp.push_back(candidates[j]);
            cntCombination(j, candidates, sum + candidates[j], target, tmp, res);
            tmp.pop_back();
        }
        return;
    }
};