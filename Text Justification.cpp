class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		if(words.empty())
		{
			string tmp(L,' ');
			vector<string> res;
			res.push_back(tmp);
			return res;
		}
		auto it = words.begin();
		vector<string> line;
		vector<string> res;
		int len = 0;
		while(it != words.end())
		{
			if(it->size() + len + line.size() <= L)
			{
				line.push_back(*it);
				len += it->size();
				it++;
			}
			else
			{
				addLine(line, len, res, L);
			}
		}
		if(!line.empty())
		{
			string tmp;
			int nonEmptyNum = 0;
			for (int i = 0; i < line.size(); i++)
			{
				if(line[i] != "")
				{
					nonEmptyNum++;
					if(line[i].size() + 1 <= L)
					{
						tmp += line[i] + ' ';
					}
					else
						tmp += line[i];
				}
					
			}
			int n = max(L - len - nonEmptyNum, 0);
			string space(n, ' ');
			tmp += space;
			res.push_back(tmp);
		}
		return res;
	}
private:
	void addLine(vector<string>& line, int& len, vector<string>& res,int L)
	{
		string tmp;
		int spaceSum = L - len;
		int spacePlus = 0;
		int spaceBase = 0;
		if(line.size() > 1)
		{
			spacePlus = spaceSum % (line.size() - 1);
			spaceBase = spaceSum / (line.size() - 1);
			for(int i = 0; i < line.size() - 1; i++)
			{
				tmp += line[i];
				int sNum;
				if(spacePlus-- > 0)
					sNum = spaceBase + 1;
				else
					sNum = spaceBase;
				string space(sNum,' ');
				tmp += space;
			}
			tmp += line[line.size() - 1];
		}
		else
		{
			spaceBase = spaceSum;
			tmp += line[0] + string(spaceBase,' ');
		}
		res.push_back(tmp);
		line.clear();
		len = 0;
	}
};