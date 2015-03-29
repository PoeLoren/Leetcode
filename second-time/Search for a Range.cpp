class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int i = 0;
        int j = n - 1;
        int left = -1;
        while(i <= j)
        {
            int mid = i + (j - i) / 2;
            if(A[mid] == target)
            {
                if(mid == 0 || A[mid - 1] < target)
                {
                    left = mid;
                    break;
                }
                else
                {
                    j = mid - 1;
                }
            }
            else if(A[mid] < target){
                i = mid + 1;
            }
            else
                j = mid - 1;
                
        }
        i = 0;
        j = n - 1;
        int right = -1;
        while(i <= j)
        {
            int mid = i + (j - i) / 2;
            if(A[mid] == target)
            {
                if(mid == n - 1 || A[mid + 1] > target)
                {
                    right = mid;
                    break;
                }
                else
                {
                    i = mid + 1;
                }
            }
            else if(A[mid] < target){
                i = mid + 1;
            }
            else
                j = mid - 1;
        }
        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};