//²âÊÔÑùÀý:"-1","0","+1","   89","+-2"

#include <iostream>
#include <string>


using namespace std;
#define MAX 2147483647

class Solution {
public:
    int atoi(const char *str) {
        long long num = 0;
		int i = 0;
		bool flag = true;
		if (str == NULL) return 0;
		for(; i< strlen(str);i++){
			if(str[i] == ' ')
				continue;
			else 
				break;
		}
		if(str[i] == '-' || str[i] == '+'){
			
			if(str[i] == '-')
				flag = false;
			i++;
		}
			
		for(; i< strlen(str);i++){
			if(str[i] >= '0' && str[i] <= '9'){
				num = num * 10 + str[i] - '0';
			}
			else 
				break;
		}
		if(num > MAX)
		{
			num = MAX;
			if(!flag) num = MAX;
		}
		if(!flag) num = -num;
		return num;
    }
};

int main()
{
	Solution s;
	int n = s.atoi("-2147483648");
	cout << n << endl;
	system("pause");
	return 0;
}
