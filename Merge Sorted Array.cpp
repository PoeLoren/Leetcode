class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(n == 0)
            return;
        int pos = m + n -1;
        int i = m-1;
        int j = n-1;
        while(i >= 0 && j >= 0){
            if(A[i] > B[j]){
                A[pos] = A[i];
                i--;
            }else{
                A[pos] = B[j];
                j--;
            }
            pos--;
        }
        while(j >= 0){
            A[pos--] = B[j--];
        }
        
    }
};