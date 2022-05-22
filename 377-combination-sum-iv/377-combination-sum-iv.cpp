class Solution {
public:
    int combinationSum4(vector<int>& nums, int n) {
        
        sort(nums.begin(), nums.end());
        
        vector<unsigned int> n_coins(n+1, 0);
        
        // no coin.
        n_coins[0] = 1;
        
        for (int i = 1; i <= n ; ++i) {
            for (int j = 0; j < nums.size() && nums[j] <= i; ++j) {
                n_coins[i] += n_coins[i - nums[j]];
            }
        }
        
        return n_coins.back();
    }
};