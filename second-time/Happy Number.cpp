class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        nums.insert(n);
        while(n != 1)
        {
            n = convert(n);
            if(nums.find(n) != nums.end())
                return false;
            nums.insert(n);
        }
        return true;
    }
    
    int convert(int n)
    {
        int ret = 0;
        while(n)
        {
            int k = n % 10;
            ret += k * k;
            n /= 10;
        }
        return ret;
    }
};