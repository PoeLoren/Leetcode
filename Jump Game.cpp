class Solution {
public:
    bool canJump(int A[], int n) {
        int curMax = 0;
        int lastMax = 0;
        for(int i = 0; i < n;i++){
            if(curMax >= n-1)
                return true;
            if(i > lastMax){
                lastMax = curMax;
            }
            curMax = max(curMax,i + A[i]);
            if(curMax == i)
                return false;
        }
        return false;
    }
};