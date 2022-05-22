class Solution {
public:
    int change(int n, vector<int>& coins) {
                
        vector<int> n_coins(n+1, 0);
        
        // no coin.
        n_coins[0] = 1;
        
        for (int j = 0; j < coins.size(); ++j) {
            for (int i = 1; i <= n ; ++i) {
                if (coins[j] <= i)
                    n_coins[i] += n_coins[i - coins[j]];
            }
        }
        
        return n_coins.back();
    }
};