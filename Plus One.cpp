class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int t = 0;
        for(int i = digits.size()-1;i >= 0;i--)
        {
            if(i == digits.size()-1)
            {
                digits[i] += 1;
            }
            digits[i] += t;
            t = digits[i] / 10;
            digits[i] %= 10;
        }
        if(t == 1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};