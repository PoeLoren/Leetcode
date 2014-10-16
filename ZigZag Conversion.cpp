#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		vector<vector<char>> resVec;
		resVec.resize(nRows);
		
			int i = 0;  
			while(i <s.size())  
			{  
				for(int m = 0; m < nRows && i <s.size(); ++m,++i)  
					resVec[m].push_back(s[i]);  
				for(int n = nRows-2; n > 0 && i <s.size(); --n,++i)  
					resVec[n].push_back(s[i]);  
			}  
			
			string res = "";
			for(int i = 0;i < nRows;i++){
				for(auto j = 0;j < resVec[i].size();j++){
					res += resVec[i][j];
				}
			}
			return res;
		
	}
};

int main()
{
	Solution s;
	s.convert("A", 1);
	return 0;
}