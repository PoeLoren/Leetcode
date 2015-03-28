class Solution {
public:
    
    void calNext(char* a, int n, vector<int>& nxt)
    {
        nxt[0] = -1;
        int i = 0;
        int j = -1;
        while(i < n)
        {
            if(j == -1 || a[i] == a[j])
            {
                ++i;
                ++j;
                nxt[i] = j;
            }
            else
            {
                j = nxt[j];
            }
        }
        return;
    }
    
    
    int strStr(char *haystack, char *needle) {
        if(needle[0] == '\0')
            return 0;
        int m = strlen(haystack);
        int n = strlen(needle);
        vector<int> nxt(n + 1);
        calNext(needle, n, nxt);
        int i = 0;
        int j = 0;
        while(i < m)
        {
            if(j == -1 || haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = nxt[j];
            }
            if(j == n)
                return i - j;
        }
        return -1;
    }
};