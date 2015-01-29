class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = true;
        if((dividend < 0&&divisor > 0) || (dividend >0&&divisor < 0)){
            flag = false;
        }
        long long c = dividend;//abs(-2147483648) will overflow
        long long d = divisor;
        long long a = abs(c);
        long long b = abs(d);
        if(a < b)
            return 0;
        long long res = 0;
        while(a >= b){
            long long count = 1;
            long long sum = b;
            while(a >= sum + sum){
                sum += sum;
                count += count;
            }
            res += count;
            a -= sum;
        }
        if(!flag)
            res = -res;
        else if(res > INT_MAX) //res = 2147483648 will overflow
            res = INT_MAX;
        return res;
    }
};