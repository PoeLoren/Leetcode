class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0;
        int r = n;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(A[mid] == target)
                return mid;
            if(A[l] < A[mid])
            {
                if(A[l] <= target && target < A[mid])
                    r = mid;
                else
                    l = mid + 1;
            }
            else
            {
                if(A[mid] < target && target <= A[r - 1])
                    l = mid + 1;
                else
                    r = mid;
            }
        }
        return -1;
    }
};