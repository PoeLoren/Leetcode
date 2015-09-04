class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        long i = 31;
        while(i >= 0)
        {
            if((m & (1 << i))  == (n & (1 << i)))
                res |= m & (1 << i);
            else
                break;
            --i;
        }
        return res;
    }
};