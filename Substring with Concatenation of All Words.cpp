class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string,int> words;
        unordered_map<string,int> count;
        int wordSize = L[0].size();
        int wordNum = L.size();
        int strLenth = S.size();
        for(int i = 0;i < wordNum;i++)
        {
            words[L[i]]++;
        }
        vector<int> res;
        for(int i = 0;i <= strLenth - wordSize * wordNum;i++)
        {
            count.clear();
            int j = 0;
            for(;j < wordNum;j++)
            {
                string w = S.substr(i + j * wordSize,wordSize);
                if(words.find(w) == words.end())
                    break;
                count[w]++;
                if(count[w] > words[w])
                    break;
            }
            if(j == wordNum)
               res.push_back(i); 
        }
        return res;
    }
};