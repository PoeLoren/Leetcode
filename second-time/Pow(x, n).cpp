class Solution {
public:
    double pow(double x, int n) {
        bool negtive = false;
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n < 0){
            negtive = true;
            n = -n;
        }
        
        double half = pow(x, n / 2);
        double res;
        if(n & 0x1)
            res = half * half * x;
        else
            res = half * half;
        if(negtive)
            res = 1 / res;
        return res;
    }
};