class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        int zeros, ones;
        
        for (auto& s: strs) {
            
            zeros = ones = 0;
            
            for (auto& c: s) {
                zeros += (c == '0');
                ones += (c == '1');
            }
            
            for (int i = n; i >= ones; --i) {
                for (int j = m; j >= zeros; --j) {
                    dp[j][i] = max(dp[j][i], dp[j-zeros][i-ones] + 1);
                }
            }
            
        }
        
        return dp.back().back();
        
    }
};