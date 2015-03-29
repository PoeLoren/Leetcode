class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int res = 0;
        while(*s != '\0')
        {
            int length = 0;
            while(*s != '\0' && *s != ' '){
                ++s;
                ++length;
            }
            while(*s == ' ')
                ++s;
            res = length;
        }
        return res;
    }
};