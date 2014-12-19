class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star = NULL;//the position of '*'
        const char* rs = NULL;//'*' matches the string beftor rs of s;
        while(*s)
        {
            if(*s == *p || *p == '?')
            {
                s++;
                p++;
                continue;
            }
            if(*p == '*')
            {
                star = p;//record the position of '*'
                p++;
                rs = s;
                continue;
            }
            if(star != NULL)//asume that '*' matches the string before rs
            {
                p = star+1;
                rs++;
                s = rs;
                continue;
            }
            return false;
        }
        while(*p == '*')
            p++;
        return *p == '\0';
    }
};