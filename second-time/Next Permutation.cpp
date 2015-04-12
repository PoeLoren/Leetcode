class Solution {
public:
    void reverseVec(int l, int r, vector<int>& num)
    {
        while(l < r)
        {
            swap(num[l], num[r]);
            l++;
            r--;
        }
        return;
    }
    void nextPermutation(vector<int> &num) {
        int l = 0;
        int r = num.size() - 1;
        int i = num.size() - 1;
        while(i > 0 && num[i - 1] >= num[i])
            i--;
        if(i == 0)
        {
            reverseVec(l, r, num);
            return ;
        }
        i--;
        int j = r;
        while(num[j] <= num[i])
            j--;
        swap(num[i], num[j]);
        reverseVec(i + 1, r, num);
        return ;
    }
};