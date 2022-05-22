class Solution {
public:
    int minDistance(string word1, string word2) {
        /**  
         *  see https://leetcode.com/problems/edit-distance/discuss/25846/C%2B%2B-O(n)-space-DP
         *
         */ 
        
        int n = word1.size();
        int m = word2.size();
        
        // dp[i][j] = the minimum step to convert
        //     word1[0...i] to word1[0...j].
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // i operation to convert word[0...i] to ""
        for(int i = 0; i <= n; ++i) 
            dp[i][0] = i;
        
        // j operation to convert word[0...j] to ""
        for (int j = 0; j <= m; ++j)
            dp[0][j] = j;
        
        // dp
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // case 1, 
                // word1[i-1] == word[j-1], no more operation needed.
                if (word1[i - 1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                // general case
                // minimum of three cases.
                else {
                    // replace
                    // replace the last word word1[i-1] to word2[j-1]
                    int rp = dp[i-1][j-1] + 1;
                    
                    // delete
                    // word1[0...i-2] -> word2[0...j-1] needs dp[i-1][j] step.
                    // delete word1[i-2] to word1[0...i-1] to reach the result. 
                    // and use dp[i-1][j] step to reach dp[i][j] 
                    int dl = dp[i-1][j] + 1;
                    
                    // insert
                    // word1[0...i-1] -> word2[0...j-2] needs dp[i][j-1] step.
                    // add word2[j-1] to the word1[0...i-1] to reach the result.
                    int is = dp[i][j-1] + 1;
                    
                    dp[i][j] = min({rp, dl, is});
                }
            }
        }
        
        
        return dp.back().back();
    }
};