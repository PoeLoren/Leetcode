//http://www.cnblogs.com/ganganloveu/p/3761715.html
class Solution {
public:
    int jump(int A[], int n) {
        int jump = 0;
        int last = 0;//the last max range
        int cur = 0;//the current max range
        for(int i = 0; i < n;i++){
            if(last < i){//need a jump
                jump++;
                last = cur;
            }
            cur = max(cur,A[i] + i);
        }
        return jump;
    }
};