class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int l = 0;
        int r = 0;
        unordered_map<int, int> umap;
        umap[s[0]] = 0;
        int res = 1;
        for(int i = 1; i < s.size(); ++i){
            if(umap.find(s[i]) == umap.end() || umap[s[i]] < l){
                res = max(res, i - l + 1);
            }
            else{
                l = umap[s[i]] + 1;
            }
            umap[s[i]] = i;
        }
        return res;
    }
};