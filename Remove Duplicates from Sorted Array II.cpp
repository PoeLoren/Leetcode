class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
            return 0;
        int len = 1;//the lenth of current number
        int last = 1;//the last possible insert index
        int num = A[0];//current number value
        for(int i = 1;i < n;i++){
            if(A[i] == num){
                len++;
                if(len > 2){
                    continue;
                }else{
                    A[last] = A[i];
                    last++;
                }
            }else{
                len = 1;
                num = A[i];
                A[last] = A[i];
                last++;
            }
        }
        return last;
    }
};