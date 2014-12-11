class Solution {
public:
    string longestPalindrome(string s) {
        int maxi = 0;
        int max = 1;
        int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n * n, false);//using vector will cause time limit out
        for(int i = 0;i < n;i++)
        {
            f[i][i] = true;
        }
        for(int i = 1;i < s.size();i++)//i means lenth
        {
            for(int j = 0;j + i < s.size();j++)
            {
                int e = j + i;
                if((i < 2 || f[j + 1][e-1]) && s[e] == s[j])
                {
                    f[j][e] = true;
                    if(i + 1 > max)
                    {
                        max = i + 1;
                        maxi = j;
                    }
                }
            }
        }
        return s.substr(maxi,max);
    }
};