class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0;
        int blue = n-1;
        for(int i = 0; i < blue + 1;){//notice i < blue + 1
            if(A[i] == 0){
                swap(A[i++],A[red++]);
            }else if(A[i] == 2){
                swap(A[i],A[blue--]);
            }else{
                i++;
            }
        }
    }
};