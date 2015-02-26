class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i < numbers.size(); ++i){
            umap[numbers[i]] = i;
        }
        vector<int> res;
        for(int i = 0;i < numbers.size(); ++i){
            if(umap.find(target - numbers[i]) != umap.end() && umap[target - numbers[i]] != i){
                res.push_back(i + 1);
                res.push_back(umap[target - numbers[i]] + 1);
            }
        }
        return res;
    }
};