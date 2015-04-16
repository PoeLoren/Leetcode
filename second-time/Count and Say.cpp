class Solution {
public:
    string countAndSay(int n) {
        if(n == 0)
            return "";
        string res = "1";
        if(n == 1)
            return res;
        for(int i = 2; i <= n; ++i)
        {
            string tmp;
            char c = res[0];
            int num = 0;
            int j = 0;
            while(j < res.size())
            {
                while(j < res.size() && res[j] == c)
                {
                    ++j;
                    ++num;
                }
                tmp.push_back(num + '0');
                tmp.push_back(c);
                if(j != res.size())
                {
                    c = res[j];
                    num = 0;
                }
            }
            res = tmp;
        }
        return res;
    }
};