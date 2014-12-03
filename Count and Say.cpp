class Solution {
public:
    string countAndSay(int n) {
        if(n == 0)
            return "";
        if(n == 1)
            return "1";
        string s = "11";
        for(int i = 2; i < n;i++)
        {
            string nxt;
            for(int j = 0;j < s.size();)
            {
                int num = 1;
                while(j + 1 < s.size() && s[j] == s[j+1])
                {
                    num++;
                    j++;
                }
                char a[3];
                a[0] = '0' + num;
                a[1] = s[j];
                a[2] = '\0';
                string k(a);
                nxt += k;
                j++;
            }
            s = nxt;
        }
        return s;
    }
};