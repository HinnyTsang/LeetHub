class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_profit = 0;
        int holding = prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > holding) 
                max_profit += prices[i] - holding;
            holding = prices[i];
        }
        
        return max_profit;
    }
};