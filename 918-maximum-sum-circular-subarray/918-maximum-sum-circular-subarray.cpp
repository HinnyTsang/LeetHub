class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /**
         * There are two possibility 
         * 1. maximum subarray is in the middle.
         * 2. The maximum subarray is wrapped. (array sum - minimum subarray in the middle.)
         */
        
        // for total sum
        int total_sum = nums[0];
        // for minimum inner subarray
        int par_min = nums[0], sub_min = nums[0];
        // for maximum inner subarray
        int par_max = nums[0], sub_max = nums[0];
        
        
        for (int i = 1; i < nums.size(); ++i) {
            
            par_min = par_min > 0? nums[i]: par_min + nums[i];
            sub_min = min(sub_min, par_min);
            
            par_max = par_max < 0? nums[i]: par_max + nums[i];
            sub_max = max(sub_max, par_max);
            
            total_sum += nums[i];
        }
    
        
        return sub_max < 0? sub_max: max(sub_max, total_sum - sub_min);
    }
};