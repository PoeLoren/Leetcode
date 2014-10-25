class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0)
            return 0;
        int sum = A[0];
        int m = A[0];
        for(int i = 1; i < n;i++){
            sum = max(sum + A[i],A[i]);
            m = max(m,sum);
        }
        return m;
    }
};