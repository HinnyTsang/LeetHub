class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int sell = 0;
        int buy = -prices[0];
        
        for (int i = 0; i < prices.size(); ++i) {
            int temp = sell;
            sell = max(sell, buy + prices[i] - fee);
            buy = max(buy, temp - prices[i]);
        }
        
        return sell;
    }
};