class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size() - 1;
        int l = 0;
        int r = size;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(mid > 0 && mid  < num.size()-1 && num[mid] < num[mid-1] && num[mid] < num[mid+1])
                return num[mid];
            if (num[mid] > num[size]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return num[l];
    }
};

class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size() - 1;
        int l = 0;
        int r = size;
        if(num[l] <= num[r])
            return num[l];
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (num[l] <= num[mid] && num[mid] <= num[r])
            {
                // is a sorted array 
                break;
            }
            if (num[mid] < num[l]) {
                r = mid ;
            } else if(num[mid] > num[r]) {
                l = mid + 1;
            }
        }
        return num[l];
    }
};