class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f(s.size() + 1, false);
        vector<vector<bool> > p(s.size() + 1,vector<bool> (s.size() + 1,false));
        f[0] = true;
        for(int i = 1;i <= s.size();i++)
        {
            for(int j = 0; j < i;j++)
            {
                if(f[j] && dict.find(s.substr(j,i - j)) != dict.end())
                {
                    f[i] = true;
                    p[j][i] = true;
                }
            }
        }
        vector<string> path;
        vector<string> res;
        DFS(p,s,dict,s.size(),path,res);
        return res;
    }
    
    void DFS(vector<vector<bool> >& p,string &s, unordered_set<string>& dict,int l,vector<string>& path,vector<string>& res)
    {
        if(l == 0)
        {
            string tmp;
            for(int i = path.size() - 1; i >= 0;i--)
            {
                tmp += path[i] + " ";
            }
            tmp.erase(tmp.end() -1);
            res.push_back(tmp);
        }
        else
        {
            for(int i = 0;i < s.size();i++)
            {
                if(p[i][l])
                {
                    path.push_back(s.substr(i,l-i));
                    DFS(p,s,dict,i,path,res);
                    path.pop_back();
                }
            }
        }
    }
};