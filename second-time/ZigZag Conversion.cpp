class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1)
            return s;
        vector<string> res(nRows);
        int radix = nRows * 2 - 2;
        for(int i = 0; i < s.size(); ++i){
            int idx = i % radix;
            if(idx < nRows)
                res[idx] += s[i];
            else
                res[radix - idx] += s[i];
        }       
        string r;
        for(int i = 0; i < res.size(); ++i)
            r += res[i];
        return r;
    }
};