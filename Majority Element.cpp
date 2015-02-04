class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 0;
        int n = 0;
        for(int i = 0; i < num.size(); ++i)
        {
            if(count == 0)
            {
                n = num[i];
                count++;
            }
            else if(num[i] == n)
                count++;
            else
                count--;
        }
        return n;
    }
};