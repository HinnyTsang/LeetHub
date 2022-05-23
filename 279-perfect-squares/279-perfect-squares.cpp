class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n + 1, 0);
        
        iota(dp.begin(), dp.end(), 0);
        
        for (int i = 0; i <= n; ++i) {
            for (int sq = 1; sq * sq <= i; ++sq) {
                dp[i] = min(dp[i], dp[i - sq*sq] + 1);    
            }
        }
        
        return dp.back();
    }
};