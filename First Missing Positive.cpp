class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n == 0)
            return 1;
        if(n == 1){
            if(A[0] == 1)
                return 2;
            else
                return 1;
        }
        bucket_sort(A,n);
        for(int i = 1; i< n; i++){
            if(i != A[i])
                return i;
        }
        if(A[0] == n)
            return n+1;
        return n;
    }
    
    void bucket_sort(int A[],int n){
        for(int i = 0; i< n; i++){
            while(A[i] != i){
                if(A[i] <0||A[i] >=n || A[i] ==A[A[i]]){
                    break;
                }
                swap(A[i],A[A[i]]);
            }
        }
       
    }
};