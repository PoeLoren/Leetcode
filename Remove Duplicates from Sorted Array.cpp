class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
            return 0;
        int first = A[0];
        int len = 0;
        for(int i = 1;i < n;i++){
            if(A[i] == first)
            {
                len++;
            }else{
                first = A[i];
                A[i-len] = A[i];
            }
        }
        return n-len;
    }
};