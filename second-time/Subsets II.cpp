class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(0, path, res, nums);
        return res;
    }
    
    void dfs(int k, vector<int>& path, vector<vector<int>>& res, const vector<int>& nums)
    {
        res.push_back(path);
        for(int i = k; i < nums.size(); ++i)
        {
            if(i != k && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            dfs(i + 1, path, res, nums);
            path.pop_back();
        }
        return;
    }
};