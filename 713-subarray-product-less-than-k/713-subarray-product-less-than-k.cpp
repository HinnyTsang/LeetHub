class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int res = 0;
        long long prod = 1;
        int l = 0, r = 0;
        
        
        for (; r < nums.size(); ++r) {
            prod *= nums[r];
            while (l <= r && prod >= k) {
                prod /= nums[l++];
            }
            res += r - l + 1; 
        }
        
        
        return res;
    }
};