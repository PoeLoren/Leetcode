class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int k = 0;
        string res;
        int i = 0;
        for(; i < a.size() && i < b.size(); ++i)
        {
            int n = a[i] - '0' + b[i] - '0' + k;
            k = n / 2;
            n %= 2;
            char c = n + '0';
            res.push_back(c);
        }
        for(; i < a.size(); ++i)
        {
            int n = a[i] - '0' + k;
            k = n / 2;
            n %= 2;
            char c = n + '0';
            res.push_back(c);
        }
        for(; i < b.size(); ++i)
        {
            int n = b[i] - '0' + k;
            k = n / 2;
            n %= 2;
            char c = n + '0';
            res.push_back(c);
        }
        if(k != 0)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};