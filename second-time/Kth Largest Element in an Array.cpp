class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }
    int findKthLargest(vector<int>& nums, int start, int end, int k)
    {
        int index = partition(nums, start, end);
        if(index + 1 == k)
            return nums[index];
        else if(index + 1 < k)
            return findKthLargest(nums, index + 1, end, k);
        else
            return findKthLargest(nums, start, index-1, k);
    }
    
    int partition(vector<int>& nums, int start, int end)
    {
        if(start >= end)
            return start;
        int pivot = nums[end];
        int cur = start;
        for(int i = start; i < end; ++i)
        {
            if(nums[i] >= pivot)
            {
                swap(nums[i], nums[cur]);
                cur++;
            }
        }
        swap(nums[cur], nums[end]);
        return cur;
    }
};