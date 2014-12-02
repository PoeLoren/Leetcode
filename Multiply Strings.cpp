class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        if(num1 == "0" || num2 == "0")
            return "0";
		for(int i = num2.size() - 1;i >= 0;i--)
		{
			string tmp(num1.size(),'0');
			int t = 0;
			for(int j = num1.size() - 1;j >= 0;j--)
			{
				int n = t + (num2[i] - '0') * (num1[j] - '0');
				t = n / 10;
				tmp[j] = n % 10 + '0';
			}
			if(t != 0)
				tmp.insert(tmp.begin(),'0' + t);
			if(res == "")//the first iterater
				res = tmp;
			else
			{
				tmp.append(num2.size() - 1 - i,'0');
				addStr(res,tmp);
			}
		}
		return res;
    }
    
   void addStr(string& res,string tmp)
	{
		string add(max(res.size(),tmp.size()),'0');
		int i = res.size() -1;
		int j = tmp.size() -1;
		int t = 0;
		while(i >= 0 && j >= 0)
		{
			int n = t + res[i] - '0' + tmp[j] - '0';
			t = n / 10;
			add[j] = n % 10 + '0';
			i--;
			j--;
		}
		while(j >= 0)//the rest tmp string's number
		{
			add[j] = t + tmp[j];
			t = (add[j] - '0') / 10;
			if(add[j] >= 10 + '0')
				add[j] -= 10;
			j--;
		}
		if(t > 0) 
		{
			add.insert(add.begin(),'1');
		}
		res = add;
	}
};