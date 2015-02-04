bool cmp(string a, string b)
{
    if(a + b > b + a)
        return true;
    else
        return false;
    
}
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> snum;
        for(int i = 0; i < num.size(); ++i)
        {
            stringstream ss;
            ss << num[i];
            string tmp;
            ss >> tmp;
            snum.push_back(tmp);
        }
        sort(snum.begin(), snum.end(), cmp);
        string res = snum[0];
        if(res == "0")
            return res;
        for(int i = 1; i < snum.size(); ++i)
        {
            res += snum[i];
        }
        return res;
    }
};