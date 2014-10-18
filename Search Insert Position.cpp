class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0;
        int r = n-1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(A[mid] == target)//found
                return mid;
            else if(A[mid] < target)
                l = mid + 1;
            else
                r = mid -1;
        }
        if(A[l] < target)//if not found
            return l + 1;
        else
            return l;
    }
};