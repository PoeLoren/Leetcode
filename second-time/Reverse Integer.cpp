class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if(x < 0){
            flag = true;
            x = -x;
        }
        long long res = 0;
        while(x > 0){
            int t = x % 10;
            x /= 10;
            res = res * 10 + t;
            if(res > INT_MAX){
                break;
            }
        }
        if(flag){
            if(res > INT_MAX)
                return 0;
            else
                return -res;
        }
        else{
            if(res > INT_MAX)
                return 0;
            else
                return res;
        }
    }
};