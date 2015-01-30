class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> cStack;
        int len = 0;
        int last = -1;//last ')' is the point between groups
        for(int i = 0;i < s.size();i++)
        {
            if(s[i] == '(')
            {
                cStack.push(i);
            }
            else
            {
                if(cStack.empty())//no '(' match
                    last = i;
                else
                {
                    cStack.pop();
                    if(cStack.empty())//there are two kind of situation 
                    {
                        len = max(len,i-last);//")","()))()()", maxlen is between last ')' of group and current ')'
                    }
                    else
                    {
                        len = max(len,i-cStack.top());//"((()()())", maxlen is between peer '(' and current ')'
                    }
                }
            }
        }
        return len;
    }
};