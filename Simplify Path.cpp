class Solution {
public:
	string simplifyPath(string path) {
		vector<string> tmp;
		for(auto i = path.begin(); i != path.end();)
		{
		    i++;
			auto j = find(i,path.end(),'/');
			string s = string(i,j);
			if(s != "" && s != ".")
			{
			    if(s == "..")
			    {
			        if(!tmp.empty())
                        tmp.pop_back();
			    }
			    else
			    {
			        tmp.push_back(s);
			    }
			}
			i = j;
		}
		string res;
		if(tmp.empty())
			res += '/';
		for(int i = 0; i < tmp.size(); i++)
		{
			res = res + '/' + tmp[i];
		}
		return res;
	}
};