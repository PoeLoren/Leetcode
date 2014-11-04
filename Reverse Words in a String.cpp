class Solution {
public:
    void reverseWords(string &s) {
        string tmp;
        queue<string> words;
        string res;
        int i = s.size()-1;
        bool flag = false;
        while(i >= 0){
            while(s[i] == ' ' && i >= 0)
                i--;
            while(s[i] != ' ' && i >= 0){
                tmp.insert(tmp.begin(),s[i]);
                i--;
                flag  = true;
            }
            if(flag){
                words.push(tmp);
                tmp = "";
                flag = false;
            }
        }
        while(!words.empty()){
            res += words.front();
            words.pop();
            if(!words.empty())
                res += ' ';
        }
        s = res;
    }
};