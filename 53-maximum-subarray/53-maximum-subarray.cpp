class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_sum = nums[0];
        int par_sum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            par_sum = par_sum < 0? nums[i]: par_sum + nums[i];
            max_sum = max(par_sum, max_sum);
        }
        
        return max_sum; 
    }
};