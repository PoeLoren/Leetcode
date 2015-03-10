class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
            return 0;
        int res = 0;
        for(int i = 1; i < n; ++i){
            if(A[i] != A[i - 1]){
                res++;
                A[res] = A[i];
            }
        }
        return res + 1;
    }
};