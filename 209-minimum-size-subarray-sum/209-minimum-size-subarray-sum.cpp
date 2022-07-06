class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, l = 0, n = nums.size();
        int result = n + 1;
        
        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            
            while (sum - nums[l] >= target) {
                sum -= nums[l++];
            }
            
            if (sum >= target) {
                result = min(result, r - l + 1);
            }
        }
        return result == n + 1? 0: result;
    }
};