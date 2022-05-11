class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = -prices[0];
        int sell = 0;
        int prev_sell = 0;
        
        for (int i = 0; i < prices.size(); ++i ) {
            int temp = sell;
            sell = max(sell, buy + prices[i]);
            buy = max(buy, prev_sell - prices[i]);
            prev_sell = temp;            
        }
        
        return sell;
    }
};