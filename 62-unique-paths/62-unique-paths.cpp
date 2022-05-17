class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) swap (m, n);
        
        vector<int> dp(m, 1);
        
        for (int r = 1; r < n; ++r) {
            for (int c = 1; c < m; ++c) {
                dp[c] += dp[c-1];
            }
        }
        
        return dp[m-1];
    }
};