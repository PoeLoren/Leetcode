class Solution {
public:
    void sortColors(int A[], int n) {
        int zero = 0;
        int two = n - 1;
        for(int i = 0; i < two + 1;)
        {
            if(A[i] == 0)
                swap(A[i++], A[zero++]);//从A[zero]换过来的肯定是1，所以要i++
            else if(A[i] == 2)
                swap(A[i],A[two--]);//从A[two]换过来的不一定是1，所以不能i++;
            else
                i++;
        }
    }
};