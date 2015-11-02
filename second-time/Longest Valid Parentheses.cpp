class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> idxStk;
        stack<int> lstk;
        idxStk.push(-1);
        int res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
            {
                idxStk.push(i);
                lstk.push(i);
            }
            else
            {
                if(lstk.empty())
                {
                    idxStk.push(i);
                }
                else
                {
                    idxStk.pop();
                    lstk.pop();
                    int pre = idxStk.top();
                    res = max(res, i - pre);
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> idx;
        int res = 0;
        int last = -1;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                idx.push(i);
            else
            {
                if(idx.empty())
                    last = i;
                else
                {
                    idx.pop();
                    if(idx.empty())
                        res = max(res, i - last);
                    else
                    {
                        int k = idx.top();
                        res = max(res, i - k);
                    }
                }
            }
        }
        return res;
    }
};