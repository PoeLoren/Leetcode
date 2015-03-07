class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                p.push(s[i]);
            else{
                if(p.empty())
                    return false;
                else{
                    char c = p.top();
                    p.pop();
                    if(s[i] == ')' && c == '(' || s[i] == '}' && c == '{' || s[i] == ']' && c == '[')
                        continue;
                    else
                        return false;
                }
            }
        }
        if(p.empty())
            return true;
        else
            return false;
    }
};