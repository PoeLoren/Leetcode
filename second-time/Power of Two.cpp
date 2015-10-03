class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        if(n <= 0)
            return false;
        while(n)
        {
            if(n & 0x1)
                cnt++;
            n = n >> 1;
        }
        if(cnt > 1)
            return false;
        return true;
    }
};