class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0')
            return *s == '\0';
        while(*p){
            if(*(p + 1) != '*'){
                if(*s == *p || (*p == '.' && *s != '\0')){
                    s++;
                    p++;
                    continue;
                }
                else
                    return false;
            }
            else{
                while(*s == *p || (*p == '.' && *s != '\0')){
                    if(isMatch(s, p + 2))
                        return true;
                    s++;
                }
                return isMatch(s, p + 2);
            }
        }
        return *s == '\0';
    }
};