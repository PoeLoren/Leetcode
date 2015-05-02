class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int k = 0;
        digits[0]++;
        for(int i = 0; i < digits.size(); ++i)
        {
            digits[i] += k;
            k = digits[i] / 10;
            digits[i] %= 10;
            if(k == 0)
                break;
        }
        if(k != 0)
            digits.push_back(k);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};