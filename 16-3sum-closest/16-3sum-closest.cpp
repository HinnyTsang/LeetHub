class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int min_diff = INT_MAX;
        int closest = 0;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            
            int j = i + 1, k = n - 1;
            int curr;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                curr = abs(target - sum);
                
                if (curr < min_diff) {
                    closest = sum;
                    min_diff = curr;
                }
                
                if (sum > target)
                    --k;
                else
                    ++j;
            }
        }
        return closest;
    }
};