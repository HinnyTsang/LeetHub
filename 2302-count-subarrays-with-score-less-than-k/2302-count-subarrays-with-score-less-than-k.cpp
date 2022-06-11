class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long result = 0;
        long long sum = 0;
        
        int n = nums.size(); 
        int l = 0, r = 0, m = 0;
        
        for (; r < n; ++r) {
            
            sum += nums[r];
            ++m;
            
            while (l <= r && static_cast<long long>(sum) * (r - l + 1) >= k) {
                sum -= nums[l];
                ++l;
                --m;
            }
            
            result += m;
        }
        
        return result;
    }
};