class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int num_slices = 0;
        int diff = 0;
        int l = 0, r = 0;
        
        // 1, 3, 6, 4+3+2+1 = 10, an = (n-2), a0 = 1 = (an + a0) * an / 2 = (n + 1) * n /2
        for (r = 1; r < nums.size();) {
            
            diff = nums[r] - nums[l];
            
            while (r < nums.size() && nums[r] - nums[r-1] == diff)
                ++r;
            
            // Sn = n * (n + 1) / 2
            num_slices += r - l > 2 ? (r - l - 1) * (r - l - 2) / 2 : 0;
            l = r - 1;
        }
        
        
        
        return num_slices;
    }
};