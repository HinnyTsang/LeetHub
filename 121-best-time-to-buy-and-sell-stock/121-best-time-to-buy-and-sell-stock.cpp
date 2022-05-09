class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_prev = prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < min_prev) {
                min_prev = prices[i];
            }
            else {
                max_profit = max(max_profit, prices[i] - min_prev);
            }
        }
        return max_profit;
    }
};