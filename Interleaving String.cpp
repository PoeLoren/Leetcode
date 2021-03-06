class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1 + n2 != n3)
            return false;
        vector<vector<bool> > f(n1 + 1, vector<bool> (n2 + 1, false));
        f[0][0] = true;
        for(int i = 1; i <= n2; i++)
        {
            if(s3[i-1] == s2[i-1])
                f[0][i] = f[0][i-1];
        }
        for(int i = 1; i <= n1; i++)
        {
            if(s3[i-1] == s1[i-1])
                f[i][0] = f[i-1][0];
        }
        for(int i = 1; i <= n1; i++)
            for(int j = 1;j <= n2; j++)
            {
                if(s2[j-1] == s3[i+j-1] && f[i][j-1])
                    f[i][j] = true;
                else if(s1[i-1] == s3[i+j-1] && f[i-1][j])
                    f[i][j] = true;
            }
        return f[n1][n2];
    }
};