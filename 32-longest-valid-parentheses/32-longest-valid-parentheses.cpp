class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size(), max_len = 0;
        vector<int> dp(n, 0);
        
        
        // dp[0] must be zero
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') {
                // no valid parentheses end with '('
                continue;
            }
            else if (s[i] == ')') {
                if (s[i-1] == '(') {
                    // match, directly add to the prev longest sub str.
                    dp[i] = i >= 2? dp[i-2] + 2: 2;
                }
                else if (s[i-1] == ')') {
                    // '....))'
                    //      ^
                    // '...())'
                    if (i-1-dp[i-1] >= 0 && s[i-1-dp[i-1]] == '(') {
                        dp[i] = dp[i-1] + 2 + dp[max(i-2-dp[i-1], 0)];    
                    }
                }
                max_len = max(max_len, dp[i]);
            }
        }
        
        return max_len;
    }
};