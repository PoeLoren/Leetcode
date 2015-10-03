class Solution {
public:
    vector<string> res;
    vector<string> addOperators(string num, int target) {
        dfs(num, target, "", 0, 0);
        return res;
    }
    
    void dfs(string num, int target, string path, long long preNum, long long curNum)
    {
        if(num.empty() && curNum == target)
        {
            res.push_back(path);
            return;
        }
        for(int i = 1; i <= num.size(); ++i)
        {
            string cur = num.substr(0, i);
            if(cur.size() > 1 && cur[0] == '0')
                return;
            string next = num.substr(i);
            long long n = stoll(cur);
            if(path.empty())
            {
                dfs(next, target, cur, n, n);
            }
            else
            {
                dfs(next, target, path + "+" + cur, n, curNum + n);
                dfs(next, target, path + "-" + cur, -n, curNum - n);
                dfs(next, target, path + "*" + cur, preNum * n, curNum - preNum + preNum * n);
            }
        }
    }
};