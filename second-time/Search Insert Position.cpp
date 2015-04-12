class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0;
        int r = n - 1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(A[mid] == target || (mid == 0 && A[mid] > target) || A[mid - 1] < target && target < A[mid])
                return mid; 
            else if(A[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
};