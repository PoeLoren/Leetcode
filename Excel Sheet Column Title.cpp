class Solution {
public:
    string convertToTitle(int n) {
        string res;
        char a[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        while(n > 0)
        {
            int k = (n - 1) % 26;
            char tmp = a[k];
            res.insert(res.begin(), tmp);
            n = (n - 1) / 26;
        }
        return res;
    }
};