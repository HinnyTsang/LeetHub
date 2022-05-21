class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // base case 1
        // no amount == no coin needed
        if (amount == 0) return 0;
        
        // sort asc
        sort(coins.begin(), coins.end());
        
        // base case 2
        // if all coin > amount, impossible to change the coin
        if (amount < coins[0]) return -1;
        
        // dp to store minimum number of coin for each amount `i`
        vector<int> dp(amount + 1, INT_MAX);
        
        // dp.
        for (int i = 0; i <= amount; ++i) {
            
            // chack all coin.
            for (auto& coin: coins) {
                
                // since coins is sorted asc,
                // coin > i means all remaining coins greater than i.
                if (coin > i) { 
                    break;
                }
                // if amount == coin, 1 coin is needed.
                else if (coin == i) {
                    dp[i] = 1;
                    break;
                }
                // if dp[i-coin] is possible, adding one more coin is possible.
                else if (dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        
        return dp.back() == INT_MAX? -1: dp.back();
    }
};