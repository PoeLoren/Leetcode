class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,bool> m;
        for(auto x:num){
            m[x] = false;
        }
        int maxlen = 0;
        for(auto x:num){
            if(m[x])
                continue;
            int len = 1;
            for(int i = x + 1;m.find(i) != m.end();i++){
                len++;
                m[i] = true;
            }
            for(int i = x - 1;m.find(i) != m.end();i--){
                len++;
                m[i] = true;
            }
            maxlen = max(maxlen,len);
        }
        return maxlen;
        
    }
};