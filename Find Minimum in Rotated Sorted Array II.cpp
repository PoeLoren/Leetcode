class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0;
        int r = num.size()-1;
        //if(num[l] <= num[r])
          //  return num[l];
        while(l < r && num[l] >= num[r])
        {
            int mid = l + (r - l) / 2;
            if(num[mid] < num[l])
                r = mid;
            else if(num[mid] > num[r])
                l = mid + 1;
            else
                l++;
        }
        return num[l];
    }
};