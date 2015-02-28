class Solution {
public:
    int atoi(string str) {
        long long res = 0;
        bool flag = true;
        int i = 0;
        while(str[i] == ' ')
            i++;
        if(str[i] == '-' || str[i] == '+'){
            if(str[i] == '-')
                flag = false;
            i++;
        }
        for(;i < str.size(); ++i){
            if(str[i] < '0' || str[i] > '9')
                break;
            res = res * 10 + str[i] - '0';
            if(res > INT_MAX)
                break;
        }
        if(!flag)
            res = -res;
        if(res > INT_MAX)
            res = INT_MAX;
        if(res < INT_MIN)
            res = INT_MIN;
        return res;
    }
};