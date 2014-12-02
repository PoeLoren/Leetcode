//My own solution
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        vector<bool> visited(num.size(),false);
        for(int i = 0;i < num.size();i++)
        {
            if(i != 0 && num[i] == num[i-1])
                continue;
            vector<int> vec;
            dfs(num,res,visited,i,vec,1);
        }
        return res;
    }
    
    void dfs(const vector<int>& num,vector<vector<int> > &res,vector<bool> &visited,const int i,vector<int>& vec,int cnt)
    {
        vec.push_back(num[i]);
        if(cnt == num.size())
        {
            res.push_back(vec);
            vec.pop_back();
            return ;
        }
        visited[i] = true;
        bool first = true;
        int last = 0;
        for(int i = 0;i < num.size();i++)
        {
            if(visited[i] == false)
            {
                if(first)
                {
                    first = false;
                    last = num[i];
                    dfs(num,res,visited,i,vec,cnt+1);
                }
                else if(num[i] != last)
                {
                    last = num[i];
                    dfs(num,res,visited,i,vec,cnt+1);
                }
            }
        }
        vec.pop_back();
        visited[i] = false;
        
    }
};

//others
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        vector<bool> visited(num.size(),false);
        vector<int> vec;
        dfs(num,res,visited,0,vec,0);
        return res;
    }

    void dfs(const vector<int>& num,vector<vector<int> > &res,vector<bool> &visited,const int i,vector<int>& vec,int cnt)
    {
        if(cnt == num.size())
        {
            res.push_back(vec);
            return ;
        }
        for(int i = 0;i < num.size();i++)
        {
            if(visited[i] == true || (i != 0 && num[i] == num[i-1] && visited[i-1] == false))
                continue;
            vec.push_back(num[i]);
            visited[i] = true;
            dfs(num,res,visited,i,vec,cnt+1);
            vec.pop_back();
            visited[i] = false;
        }
    }
};