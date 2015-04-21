class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > m;
        for(int i = 0; i < strs.size(); ++i)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            m[key].push_back(strs[i]);
        }
        auto it = m.begin();
        vector<string> res;
        for(; it != m.end(); ++it)
        {
            if(it->second.size() > 1)
                res.insert(res.end(), it->second.begin(), it->second.end());
        }
        return res;
    }
};