class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string,vector<string> > group;
        for(auto &s:strs){
            string key = s;
            sort(key.begin(),key.end());
            group[key].push_back(s);
        }
        
        vector<string> res;
        for(auto i = group.cbegin();i != group.cend();i++){
            if(i->second.size() > 1){
                res.insert(res.end(),i->second.begin(),i->second.end());
            }
        }
        return res;
    }
};