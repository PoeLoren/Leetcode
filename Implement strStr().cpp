class Solution {
public:
    int strStr(char *haystack, char *needle) {
        //n = strlen(haystack);
        if(needle[0] == '\0')
            return 0;
        m = strlen(needle);
        getNext(needle);
        int j = 0;
        for(int i = 0;haystack[i] != '\0';i++)
        {
            while(j > 0 && haystack[i] != needle[j])
                j = next[j];
            if(haystack[i] == needle[j])
                j++;
            if(j == m)
                return i - m + 1;
        }
        return -1;
    }
private:
    int n;
    int m;
    vector<int> next;
    void getNext(char* s)
    {
        int j = 0;
        next.resize(m + 1);
        next[0] = next[1] = 0;
        for(int i = 2; i <= m; i++)
        {
            while(j > 0 && s[j] != s[i - 1])
                j = next[j];
            if(s[j] == s[i-1])
                j++;
            next[i] = j;
        }
    }
};