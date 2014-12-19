class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if(num.size() == 1)
            return 0;
        if(num.size() == 2)
            return num[0] > num[1] ? 0 : 1;
        int a = 1;
        int n = num.size();
        while(a < n && num[a] > num[a - 1])
            a *= 2;
        int l = a / 2;
        int r = min(a, n-1);
        int mid = l + (r - l) / 2;
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            if(mid == 0 || mid == n-1)
                break;
            if(num[mid] > num[mid - 1] && num[mid] > num[mid + 1])
                return mid;
            if(num[mid] > num[mid - 1])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return mid;
    }
};