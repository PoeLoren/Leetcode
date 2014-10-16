//A better method http://blog.csdn.net/pickless/article/details/9018575
#include <iostream>

using namespace std;

int main()
{
	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int maxlen = 0,len = 0,start_index = 0;
			int alphet[300][2];
			memset(alphet,0,sizeof(alphet));
			for(string::size_type i = 0;i < s.size();++i)
			{
				char c = s[i];
				if(alphet[c][0] == 0)
				{
					len++;
					if(len > maxlen)
						maxlen = len;
					alphet[c][0]++;
					alphet[c][1] = i;
				}
				else
				{
					len = len - (alphet[c][1] - start_index);
					for(;start_index < alphet[c][1];++start_index)
					{
						char ctemp = s[start_index];
						alphet[ctemp][0] = 0;
					}
					
					start_index = alphet[c][1] + 1;
					alphet[c][1] = i;
				}
			}
			return maxlen;
		}
	};

	Solution s;
	string s1("bbbbbbbyuii");
	cout << s.lengthOfLongestSubstring(s1) <<endl;
	return 0;
}