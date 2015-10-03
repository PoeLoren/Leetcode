class Solution {
public:
    vector<int> fac;
    void calFac(int n)
    {
        fac.resize(n + 1);
        fac[0] = 1;
        for(int i = 1; i <= n; ++i)
            fac[i] = fac[i-1] * i;
    }
    string getPermutation(int n, int k) {
        calFac(n);
        string res;
        vector<int> a(n + 1);
        k--;
        for(int i = 0; i <= n; ++i)
            a[i] = i + 1;
        for(int i = n - 1; i >= 0; --i)
        {
            int mod = k % fac[i];
            int r = k / fac[i];
            res += '0' + a[r];
            k = mod;
            for(int j = r; j <= n; ++j)
                a[j] = a[j + 1];
        }
        return res;
    }
};