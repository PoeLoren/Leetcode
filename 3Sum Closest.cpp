class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret = target;
        int diff = 9999999;
        sort(num.begin(),num.end());
        set<int> visited;
        for(int i = 0; i < num.size()-2;i++)
        {
            if(visited.find(num[i]) == visited.end()){
                visited.insert(num[i]);
                int subRet = twoSum(i+1,target-num[i],num);
                if(abs(subRet + num[i]-target) < diff){
                    ret = subRet + num[i];
                    diff = abs(subRet + num[i]-target);
                }
            }
        }
        return ret;
    }
    
    int twoSum(int begin,int target,vector<int> &num){
        int l = begin;
        int r = num.size()-1;
        int ret = target;
        int diff = 999999;
        while(l < r){
            int sum = num[l] + num[r];
            if(abs(sum-target) < diff ){
                ret = sum;
                diff = abs(sum-target);
            }
            if ( sum < target){
                l++;
            }else{
                r--;
            }
        }
        return ret;
    }
};