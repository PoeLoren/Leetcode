class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        queue<string> q;
        string endNode = start;
        q.push(start);
        int len = 0;
        bool flag = false;
        dict.erase(start);//It's possible that start string is in the dict
        while(!q.empty())
        {
            string cur = q.front();
            if(cur == end)
            {
                flag = true;
                break;
            }
            q.pop();
            for(int i = 0; i < start.size();i++)//enum all possible string
            {
                string tmp = cur;
                for(char j = 'a';j < 'z'; j++)
                {
                    if(tmp[i] == j)
                        continue;
                    tmp[i] = j;
                    if(dict.find(tmp) != dict.end())
                        q.push(tmp);
                    dict.erase(tmp);//if tmp string is push into queue, delete from dict. for memory limit out
                }
            }
            if(cur == endNode)
            {
                len++;
                if(!q.empty())
                    endNode = q.back();
            }
        }
        if(flag)
            return len+1;
        else
            return 0;
    }
};