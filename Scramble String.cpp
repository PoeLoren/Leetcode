//http://blog.csdn.net/pickless/article/details/11501443
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        int n = s1.size();
        bool f[n][n][n];
        fill_n(&f[0][0][0], n * n * n, false);
        for(int k = 1;k <= n;k++)
        {
            for(int i = 0; i <= n - k;i++)
                for(int j = 0; j <= n - k;j++)
                {
                    if(k == 1)
                        f[i][j][k] = s1[i] == s2[j];
                    else
                    {
                        for(int l = 1; l < k;l++)
                        {
                            if(f[i][j][l] && f[i + l][j + l][k - l] || f[i][j + k-l][l] && f[i + l][j][k-l])
                            {
                                f[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
        }
        return f[0][0][n];
    }
};