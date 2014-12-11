class Solution {
public:
    int numDecodings(string s) {
        vector<int> f(s.size(),0);
        if(s.empty())
            return 0;
        int a = 0,b = 0,c = 0;
        if(s[0] != '0')
             b = 1;
        if(s.size() == 1)
            return b;
        for(int i = 1;i < s.size();i++)
        {
            c = 0;
            string tmp(s,i-1,2);
            if(tmp >= "10" && tmp <= "26")
            {
                if(i == 1)
                {
                    c++;
                }
                else
                    c += a;
            }
            if(s[i] != '0')
                c += b;
            a = b;
            b = c;
        }
        return c;
    }
};