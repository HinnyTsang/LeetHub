class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int result = 0, n = nums.size();
        int l = 0;
        long long prod = 1;
        
        for (int r = 0; r < n; ++r) {
            if (nums[r] >= k) {
                prod = 1, l = r + 1;
                continue;
            }
            prod *= nums[r];
            while (prod >= k) {
                prod /= nums[l++];
            }
            result += r - l + 1;
        }
        
        return result;
    }
};