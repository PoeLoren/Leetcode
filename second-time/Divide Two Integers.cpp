class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)
            return INT_MAX;
        bool flag = false;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        {
            flag = true;
        }
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long res = 0;
        while(a >= b){
             long long tmp = b;
             long long tmpRes = 1;
             while(tmp + tmp <= a){
                 tmp += tmp;
                 tmpRes += tmpRes;
             }
             res += tmpRes;
             a -= tmp;
        }
        if(flag){
            return -res;
        }
        else{
            if(res > INT_MAX)
                return INT_MAX;
            return res;
        }
    }
};