class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
            return 0;
        int p1 = 0;
        int p2 = 1;
        int i = 0;
        while(i < n)
        {
            int tmp = p2;
            p2 = p1 + p2;
            p1 = tmp;
            ++i;
        }
        return p2;
    }
};