class Solution {
public:
    double pow(double x, int n) {
        if(n == 0)
            return 1;
        double res = 1;
        bool neg = false;
        if(n < 0)
        {
            neg = true;
            n = -n;
        }
        if(n & 0x1 == 1)
        {
            double tmp = pow(x, n / 2);
            res = tmp * tmp * x;
        }
        else
        {
            double tmp = pow(x, n / 2);
            res = tmp * tmp;
        }
        if(neg)
            res = 1 / res;
        return res;
    }
};