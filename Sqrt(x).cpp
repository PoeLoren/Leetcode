class Solution {
public:
    int sqrt(int x) {
        if(x < 2)
            return x;
        int l = 1;
        int r = x / 2;
        int lastMid;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(mid < x / mid)
            {
                l = mid + 1;
                lastMid = mid;
            }
            else if(mid > x / mid)
            {
                r = mid -1;
            }
            else
                return mid;
        }
        return lastMid;
    }
};