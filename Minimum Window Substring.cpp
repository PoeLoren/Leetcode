//http://www.tuicool.com/articles/ZnuEVfJ
class Solution {
public:
    string minWindow(string S, string T) {
        const int ASCII = 256;
        int exp[ASCII] = {0};
        int app[ASCII] = {0};
        for(int i = 0;i < T.size();i++)
            exp[T[i]]++;
        int minSize = INT_MAX;
        int minStart = 0;
        int winStart = 0;
        int appear = 0;
        for(int i = 0;i < S.size();i++)
        {
            if(exp[S[i]] > 0)
            {
                app[S[i]]++;
                if(app[S[i]] <= exp[S[i]])
                    appear++;
            }
            if(appear == T.size())
            {
                while(app[S[winStart]] > exp[S[winStart]]   //if the number of start char is greater than expected, it can be pass
                    ||exp[S[winStart]] == 0)                //or start char is not in the T string
                {
                    app[S[winStart]]--;
                    winStart++;
                }
                if(minSize > (i - winStart + 1))
                {
                    minSize = i - winStart + 1;
                    minStart = winStart;
                }
            }
            
        }
        if(minSize == INT_MAX)
            return "";
        else
            return S.substr(minStart,minSize);
            
    }
};