class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        int slen = strlen(s);
        for(int i = 0; i < slen;i++){
            if(s[i] == ' '){
                while(s[i] == ' ' && i < slen)
                    i++;
                if(i == slen)
                    break;
                len = 1;
            }
            else
                len++;
        }
        return len;
    }
};