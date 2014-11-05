class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n == 0)
            return 0;
        int f = A[n-1];
        int maxm = A[n-1];
        int minm = A[n-1];
        int res = maxm;
        for(int i = n-2;i >= 0;i--){
            int tmp = maxm * A[i];
            maxm = max(maxm * A[i],max(A[i],minm * A[i]));
            minm = min(tmp,min(A[i],minm * A[i]));
            res = max(res,maxm);
        }
        return res;
    }
};