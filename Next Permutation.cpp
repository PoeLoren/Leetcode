class Solution {
public:
    void nextPermutation(vector<int> &num) {
        const auto rfirst = num.rbegin();
        const auto rlast = num.rend();
        auto pivot = next(rfirst);
        while(pivot != rlast && ! (*pivot < *prev(pivot))){//find the first element which violate increase trend from right to left
            pivot++;
        }
        if(pivot == rlast){//if not find,reverse the vector
            reverse(num.begin(),num.end());
            return;
        }
        auto it = num.rbegin();
        while(it != pivot && !(*it > *pivot)){//find the first element greater than pivot
            it++;
        }
        swap(*it,*pivot);
        reverse(rfirst,pivot);
        return ;
        
    }
    
    
};