class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        
        if (sum % 2 == 1) return false;
        
        sum /= 2;
        
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = sum; j >= 0; --j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i-1])                
                    dp[i][j] = dp[i][j] | dp[i - 1][j - nums[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};