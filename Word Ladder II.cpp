//http://blog.csdn.net/doc_sgl/article/details/13341405
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        dict.erase(start);
        unordered_map<string,vector<string> > m;
        unordered_set<string> unset[2];
        int current = 1;
        int prev = 0;
        bool flag = false;
        string endNode = start;
        unset[prev].insert(start);
        vector<vector<string>> res;
        while(true)
        {
            unset[current].clear();
            for(auto it = unset[prev].begin(); it != unset[prev].end();it++)
            {
                dict.erase(*it);
                for(int i = 0; i < start.size(); i++)
                {
                    string tmp = *it;
                    for(char j = 'a'; j <= 'z'; j++)
                    {
                        if(tmp[i] == j)
                            continue;
                        tmp[i] = j;
                        if(dict.find(tmp) != dict.end())
                        {
                            if(unset[prev].find(tmp) == unset[prev].end())
                                m[tmp].push_back(*it);
                            unset[current].insert(tmp);
                        }
                    }
                }
            }
            if(unset[current].empty())
                return res;
            if(unset[current].find(end) != unset[current].end())
                break;
            current = !current;
            prev = !prev;
        }
        
        vector<string> path;
        path.push_back(end);
        findPath(start, m, res, path, end);
        return res;
    }
    
    void findPath(string start, unordered_map<string,vector<string> >& m, vector<vector<string>>& res, vector<string>& path, string cur)
    {
        if(cur == start)
        {
            vector<string> tmp = path;
            reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            return;
        }
        for(int i = 0;i < m[cur].size();i++)
        {
            path.push_back(m[cur][i]);
            findPath(start, m, res, path, m[cur][i]);
            path.pop_back();
        }
        
    }
};