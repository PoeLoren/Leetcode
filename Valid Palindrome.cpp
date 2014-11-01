class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        int i = 0;
        int j = s.size()-1;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(i < j){
            while(i < s.size() && !isalnum(s[i]) )
				i++;
			while(j >= 0 && !isalnum(s[j]))
				j--;
            if(i == s.size() || j <0)
                return true;
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};