class Solution {
public:
    bool isPalindrome(int x) {
        stringstream ss;
        string s;
        ss << x;
        ss >> s;
        int i =0;
        int j = s.size()-1;
        bool is = true;
        while(i < j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
};