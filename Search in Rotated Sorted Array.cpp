class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0;
        int r = n;
        while(l < r){
            const int mid = l + (r - l) / 2;
            if(A[mid] == target)
                return mid;
            if(A[l] < A[mid]){
                if(A[l] <= target && A[mid] > target)
                    r = mid;
                else 
                    l = mid + 1;
            }else{
                if(A[r-1] >= target && target > A[mid])
                    l = mid + 1;
                else
                    r = mid;
            }
        }
        return -1;
    }
};