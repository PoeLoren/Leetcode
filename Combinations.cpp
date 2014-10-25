class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combine(int n, int k) {
        
        vector<int> a;
        if(n == 1)
        {
            a.push_back(1);
            res.push_back(a);
            return res;
        }
        comb(a,1,n,k,0);
        return res;
    }
    
    void comb(vector<int>& a,int cur,int n,int target,int k){
        if(k == target){
            res.push_back(a);
        }else{
            
            for(int i = cur; i <= n;i++){
                a.push_back(i);
                comb(a,i+1,n,target,k+1);
                a.pop_back();
            }
            
        }
    }