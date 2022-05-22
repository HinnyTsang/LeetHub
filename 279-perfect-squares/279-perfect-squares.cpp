class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n + 1, 0);
        
        iota(dp.begin(), dp.end(), 0);
        
        for (int val = 2; val <= n; ++val) {
            for (int sq = 2; val >= sq*sq; ++sq) {
                dp[val] = min(dp[val], dp[val - sq*sq] + 1);
            }
        }
        
        
        return dp.back();
    }
};